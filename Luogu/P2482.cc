#include <bits/stdc++.h>

using namespace std;

struct Game {
    int n, m;
    struct Player {
        int ident; // MP 0 ZP 1 FP 2
        int life;
        list<int> cards;
        // P 0 K 1 D 2 F 3 N 4 W 5 J 6 Z 7
        bool equipped;
        Player() { ident = -1, life = 4, equipped = false; }
        Player(int a, int b, int c, int d, int e) {
            ident = a, life = 4;
            cards.assign({b, c, d, e});
            if (ident == 0) showed = true;
            lastAttacker = -1;
        }
        bool showed = false;
        bool likeF = false;
        int lastAttacker;

        bool FPL() { return likeF && !showed; }
    };

    int idx(char x) {
        switch (x) {
            case 'P': return 0;
            case 'K': return 1;
            case 'D': return 2;
            case 'F': return 3;
            case 'N': return 4;
            case 'W': return 5;
            case 'J': return 6;
            case 'Z': return 7;
            default: break;
        }
    }

    vector<Player> players;

    queue<int> pile;

    int lastOne;

    int mp;

    void init() {
        cin >> n >> m;
        auto name = [](const string &s) {
            if (s == "MP") return 0;
            if (s == "ZP") return 1;
            return 2;
        };
        for (int i = 0; i < n; i++) {
            string s;
            char a, b, c, d;
            cin >> s >> a >> b >> c >> d;
            players.emplace_back(name(s), idx(a), idx(b), idx(c), idx(d));
            if (name(s) == 0) mp = i;
        }
        for (int i = 0; i < m; i++) {
            char t;
            cin >> t;
            pile.push(idx(t));
        }
        lastOne = pile.back();
    }

    int win() { // -1 FP win 1 MP/ZP win 0 not yet
        int a[3];
        memset(a, 0, sizeof a);
        for (auto i : players) a[i.ident] += (i.life > 0);
        if (a[0] == 0) return -1;
        if (a[2] == 0) return 1;
        return 0;
    }

    int d(int a, int b) {
        int p = a, dist = 0;
        while (p != b) {
            p++;
            if (p == n) p = 0;
            if (players[p].life > 0) dist++;
        }
        return dist;
    }

    void getCard(int who, int num) {
        while (num--) {
            if (!pile.empty()) players[who].cards.push_back(pile.front()), pile.pop();
            else players[who].cards.push_back(lastOne);
        }
    }

    bool give(int target, int card) { // 1K 2D 6J
        auto p = players[target].cards.begin();
        while (p != players[target].cards.end()) {
            if (*p == card) {
                p = players[target].cards.erase(p);
                return true;
            }
            p++;
        }
        return false;
    }

    void settle(int from, int death) {
        switch (players[death].ident) {
            case 0: result(); break;
            case 1:
                if (players[from].ident == 0) {
                    players[from].equipped = false;
                    players[from].cards.clear();
                }
                break;
            case 2: getCard(from, 3); break;
        }
    }

    bool survive(int target) {
        auto p = players[target].cards.begin();
        while (p != players[target].cards.end()) {
            if (*p == 0) {
                p = players[target].cards.erase(p);
                players[target].life++;
            }
            else p++;
        }
        if (players[target].life > 0) return true;
        else settle(players[target].lastAttacker, target);
    }

    void lifeReduce(int from, int target, int amount) {
        players[target].life -= amount;
        players[target].lastAttacker = from;
        if (players[target].life <= 0) survive(target);
    }

    int identi(int id) {
        vector<int> q1, q2;
        for (int i = 0; i < players.size(); i++)
            if (players[i].showed && players[i].ident == 2) q1.push_back(i);
        for (int i = 0; i < players.size(); i++)
            if (players[i].showed && players[i].ident == 1) q2.push_back(i);
        q2.push_back(mp);
        sort(q2.begin(), q2.end());
        int flag = 0;
        int identity = 0;
        auto a1 = lower_bound(q2.begin(), q2.end(), id);
        if (a1 != q2.end() && !(id < *a1)) identity = 1;
        a1 = lower_bound(q1.begin(), q1.end(), id);
        if (a1 != q1.end() && !(id < *a1)) identity = -1;
        return identity;
    }

    bool invulnerable(int from) {
        vector<int> q1;
        for (int i = 0; i < players.size(); i++)
            if (players[i].showed && players[i].ident == 2) q1.push_back(i);
        int flag = 0;
        for (int i = from;; i++) {
            if (i == from && flag) break;
            flag = 1;
            if (i >= n) i = 0;
            if (players[i].life <= 0) continue;
            int ide = identi(i);
            if (ide != 1 && players[i].ident != 2 && give(i, 6)) {
                players[i].showed = true;
                if (invulnerable(i)) return players[i].showed = false;
                return true;
            }
            if (ide != -1 && players[i].ident == 2 && !q1.empty() && give(i, 6)) {
                players[i].showed = true;
                if (invulnerable(i)) return players[i].showed = false;
                return true;
            }
        }
        return false;
    }

    bool invul2(int from, int to) {
        int identity = identi(to);
        int flag = 0;
        for (int i = from;; i++) {
            if (i >= n) i = 0;
            if (i == from && flag) break;
            flag = 1;
            if (players[i].life <= 0) continue;
            if (identity == 1 && players[i].ident != 2 && give(i, 6)) {
                players[i].showed = true;
                if (invulnerable(i)) return players[i].showed = false;
                return true;
            }
            if (identity == -1 && players[i].ident == 2 && give(i, 6)) {
                players[i].showed = true;
                if (invulnerable(i)) return players[i].showed = false;
                return true;
            }
        }
        return false;
    }

    void IA(int from, int mode) {
        int flag = 0;
        for (int i = from;; i++) {
            if (i == from && flag) break;
            if (i == from) continue;
            if (i >= n) i = 0;
            if (players[i].life <= 0) continue;
            flag = 1;
            if (invul2(from, i)) continue;
            if (!give(i, mode)) {
                if (!players[from].showed && i == mp) players[from].likeF = true;
                lifeReduce(from, i, 1);
            }
        }
    }

    void fight(int from, int to) {
        if (invul2(from, to)) return;
        int flag = 0;
        if (from == mp && players[to].ident == 1) {
            lifeReduce(from, to, 1);
            return;
        }
        while (true) {
            if (!give(to, 1)) {
                flag = -1;
                break;
            }
            if (!give(from, 1)) {
                flag = 1;
                break;
            }
        }
        if (flag == 1) lifeReduce(to, from, 1);
        if (flag == -1) lifeReduce(from, to, 1);
    }

    void kill(int from, int to) {
        if (!give(to, 2)) lifeReduce(from, to, 1);
    }

    void game() {
        for (int i = 0; i < players.size(); i++) {
            if (players[i].life <= 0) continue;
            getCard(i, 2);
            bool killed = false;
            list<int>::iterator p = players[i].cards.begin();
            switch (players[i].ident) {
                case 0:
                    while (p != players[i].cards.end()) {
                        if (*p == 0) {
                            if (players[i].life < 4) {
                                p = players[i].cards.erase(p);
                                players[i].life++;
                            }
                            else p++;
                        }
                        else if (*p == 1) {
                            if (killed && !players[i].equipped) {
                                p++;
                                continue;
                            }
                            int flag = 0;
                            int s = -1;
                            for (int j = i;; j++) {
                                if (j >= n) j = 0;
                                if (j == i && flag) break;
                                flag = 1;
                                if ((players[j].FPL() || (players[j].showed && players[j].ident == 2)) &&
                                    d(i, j) == 1) {
                                    s = j;
                                    break;
                                }
                            }
                            if (s == -1) {
                                p++;
                                continue;
                            }
                            else {
                                p = players[i].cards.erase(p);
                                kill(i, s);
                                if (players[i].cards.empty()) break;
                            }
                        }
                        else if (*p == 2 || *p == 6) p++;
                        else if (*p == 3) {
                            int flag = 0;
                            int s = -1;
                            for (int j = i;; j++) {
                                if (j >= n) j = 0;
                                if (j == i && flag) break;
                                flag = 1;
                                if ((players[j].FPL() || (players[j].showed && players[j].ident == 2)) &&
                                    d(i, j) == 1) {
                                    s = j;
                                    break;
                                }
                            }
                            if (s == -1) {
                                p++;
                                continue;
                            }
                            else {
                                p = players[i].cards.erase(p);
                                fight(i, s);
                                if (players[i].cards.empty()) break;
                            }
                        }
                        else if (*p == 4 || *p == 5 || *p == 7) {
                            int x = *p;
                            p = players[i].cards.erase(p);
                            if (x == 4 || x == 5) {
                                IA(i, x - 3);
                                if (players[i].cards.empty()) break;
                            }
                            if (x == 7) players[i].equipped = true;
                        }
                    }
                    break;
                case 1:
                    while (p != players[i].cards.end()) {
                        if (*p == 0) {
                            if (players[i].life < 4) {
                                p = players[i].cards.erase(p);
                                players[i].life++;
                            }
                            else p++;
                        }
                        else if (*p == 1) {
                            if (killed && !players[i].equipped) {
                                p++;
                                continue;
                            }
                            int flag = 0;
                            int s = -1;
                            for (int j = i;; j++) {
                                if (j >= n) j = 0;
                                if (j == i && flag) break;
                                flag = 1;
                                if ((players[j].showed && players[j].ident == 2) && d(i, j) == 1) {
                                    s = j;
                                    break;
                                }
                            }
                            if (s == -1) {
                                p++;
                                continue;
                            }
                            else {
                                p = players[i].cards.erase(p);
                                kill(i, s);
                            }
                        }
                        else if (*p == 2 || *p == 6) p++;
                        else if (*p == 3) {
                            int flag = 0;
                            int s = -1;
                            for (int j = i;; j++) {
                                if (j >= n) j = 0;
                                if (j == i && flag) break;
                                flag = 1;
                                if ((players[j].showed && players[j].ident == 2) && d(i, j) == 1) {
                                    s = j;
                                    break;
                                }
                            }
                            if (s == -1) {
                                p++;
                                continue;
                            }
                            else {
                                p = players[i].cards.erase(p);
                                fight(i, s);
                            }
                        }
                        else if (*p == 4 || *p == 5 || *p == 7) {
                            int x = *p;
                            p = players[i].cards.erase(p);
                            if (x == 4 || x == 5) IA(i, x - 3);
                            if (x == 7 && !players[i].equipped) players[i].equipped = true;
                        }
                    }
                    break;
                case 2:
                    while (p != players[i].cards.end()) {
                        if (*p == 0) {
                            if (players[i].life < 4) {
                                p = players[i].cards.erase(p);
                                players[i].life++;
                            }
                            else p++;
                        }
                        else if (*p == 1) {
                            if (killed && !players[i].equipped) {
                                p++;
                                continue;
                            }
                            int flag = 0;
                            int s = -1;
                            if (d(i, mp) == 1) s = mp;
                            else {
                                for (int j = i;; j++) {
                                    if (j >= n) j = 0;
                                    if (j == i && flag) break;
                                    flag = 1;
                                    if ((players[j].showed && players[j].ident == 1) && d(i, j) == 1) {
                                        s = j;
                                        break;
                                    }
                                }
                            }
                            if (s == -1) {
                                p++;
                                continue;
                            }
                            else {
                                p = players[i].cards.erase(p);
                                kill(i, s);
                            }
                        }
                        else if (*p == 2 || *p == 6) p++;
                        else if (*p == 3) {
                            int flag = 0;
                            int s = -1;
                            if (d(i, mp) == 1) s == mp;
                            else {
                                for (int j = i;; j++) {
                                    if (j >= n) j = 0;
                                    if (j == i && flag) break;
                                    flag = 1;
                                    if ((players[j].showed && players[j].ident == 1) && d(i, j) == 1) {
                                        s = j;
                                        break;
                                    }
                                }
                            }
                            if (s == -1) {
                                p++;
                                continue;
                            }
                            else {
                                p = players[i].cards.erase(p);
                                fight(i, s);
                            }
                        }
                        else if (*p == 4 || *p == 5 || *p == 7) {
                            int x = *p;
                            p = players[i].cards.erase(p);
                            if (x == 4 || x == 5) IA(i, x - 3);
                            if (x == 7 && !players[i].equipped) players[i].equipped = true;
                        }
                    }
                    break;
            }
        }
    }

    char reidx(int x) {
        switch (x) {
            case 0: return 'P';
            case 1: return 'K';
            case 2: return 'D';
            case 3: return 'F';
            case 4: return 'N';
            case 5: return 'W';
            case 6: return 'J';
            case 7: return 'Z';
            default: break;
        }
    }

    void result() {
        if (win() == 1) cout << "MP" << endl;
        else cout << "FP" << endl;
        for (auto i : players) {
            if (i.life <= 0) {
                cout << "DEAD" << endl;
                continue;
            }
            auto p = i.cards.begin();
            while (p != i.cards.end()) {
                if (p != i.cards.begin()) cout << " ";
                cout << reidx(*(p++));
            }
            cout << endl;
        }
        exit(0);
    }
};

int main() {
#ifdef LOCALENV
    freopen("temp.in", "r", stdin);
    freopen("temp.out", "w", stdout);
#endif
    Game pig;
    pig.init();
    while (!pig.win()) {
        pig.game();
    }
    pig.result();
}