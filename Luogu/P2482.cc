#include <bits/stdc++.h>

using namespace std;

struct Game {
    int n {}, m {};
    struct Player {
        int ident; // MP 0 ZP 1 FP 2
        int life = 4;
        // P 0 K 1 D 2 F 3 N 4 W 5 J 6 Z 7
        struct Card {
            int type;
            bool use;
            Card() {
                type = -1;
                use = true;
            }
            Card(int a, bool b) : type(a), use(b) {};
        };

        vector<Card> cards;
        bool equipped = false;
        Player() { ident = -1, life = 4, equipped = false; }
        Player(int a, int b, int c, int d, int e) {
            ident = a, life = 4;
            cards.emplace_back(b, true);
            cards.emplace_back(c, true);
            cards.emplace_back(d, true);
            cards.emplace_back(e, true);
            if (ident == 0) showed = true;
        }
        bool showed = false, likeF = false;
        bool useKill = false;
        bool dead = false;

        void clear() {
            cards.clear();
            equipped = false;
        }

        vector<Card>::iterator find(int type) {
            for (auto it = cards.begin(); it != cards.end(); it++) {
                if (!it->use) continue;
                if (it->type == type) return it;
            }
            return cards.end();
        }

        void give(vector<Card>::iterator &x) { x->use = false; }

        bool give(int card) {
            auto p = find(card);
            if (p == cards.end()) return false;
            else give(p);
            return true;
        }

        void jump() { showed = true; }
    };

    vector<Player> players;

    queue<int> pile;
    int lastOne {};
    int FP = 0;

    void init() {
        cin >> n >> m;
        auto name = [](const string &s) {
            if (s == "MP") return 0;
            if (s == "ZP") return 1;
            return 2;
        };
        auto idx = [](char x) {
            switch (x) {
                case 'P': return 0;
                case 'K': return 1;
                case 'D': return 2;
                case 'F': return 3;
                case 'N': return 4;
                case 'W': return 5;
                case 'J': return 6;
                default: return 7;
            }
        };
        for (int i = 0; i < n; i++) {
            string s;
            char a, b, c, d;
            cin >> s >> a >> b >> c >> d;
            players.emplace_back(name(s), idx(a), idx(b), idx(c), idx(d));
            if (name(s) == 2) FP++;
        }
        for (int i = 0; i < m; i++) {
            char t;
            cin >> t;
            pile.push(idx(t));
        }
        lastOne = pile.back();
    }

    void gameResult(int res) {
        cout << ((res == 1) ? "MP" : "FP") << endl;
        auto reIdx = [](int x) {
            switch (x) {
                case 0: return 'P';
                case 1: return 'K';
                case 2: return 'D';
                case 3: return 'F';
                case 4: return 'N';
                case 5: return 'W';
                case 6: return 'J';
                default: return 'Z';
            }
        };
        for (int i = 0; i < n; i++) {
            Player &k = players[i];
            if (k.dead) cout << "DEAD" << endl;
            else {
                for (const Player::Card &j : k.cards) {
                    if (!j.use) continue;
                    cout << reIdx(j.type) << " ";
                }
                cout << endl;
            }
        }
        exit(0);
    }

    void settle() {
        if (players[0].dead) gameResult(2);
        if (FP == 0) gameResult(1);
    }

    void die(int from, int target) {
        Player &s = players[from];
        Player &t = players[target];
        t.dead = true;
        if (t.ident == 2) FP--;
        settle();
        if (t.ident == 2) getCard(from, 3);
        if (s.ident == 0 && t.ident == 1) s.clear();
    }

    void getCard(int who, int num) {
        while (num--) {
            if (!pile.empty()) {
                players[who].cards.emplace_back(pile.front(), true);
                pile.pop();
            }
            else players[who].cards.emplace_back(lastOne, true);
        }
    }

    void useCard(int from, Player::Card &x) {
        Player &s = players[from];
        switch (x.type) {
            case 0:
                if (s.life < 4) {
                    x.use = false;
                    s.life++;
                }
                break;
            case 1: {
                int target = findKill(from);
                if (target != -1) {
                    x.use = false;
                    kill(from, target);
                }
                break;
            }
            case 3: {
                int target = findFight(from);
                if (target != -1) {
                    x.use = false;
                    fight(from, target);
                }
                break;
            }
            case 4:
            case 5: {
                x.use = false;
                IA(from, x.type - 3);
                break;
            }
            case 7: {
                x.use = false;
                s.equipped = true;
            }
        }
    }

    int findKill(int from) {
        Player &u = players[from];
        if (u.useKill && !u.equipped) return -1;
        if (u.ident == 0) {
            for (int i = (from + 1) % n; i != from; i = (i + 1) % n) {
                Player &v = players[i];
                if (v.dead) continue;
                if (v.likeF || (v.ident == 2 && v.showed)) return i;
                else return -1;
            }
        }
        if (u.ident == 1) {
            for (int i = (from + 1) % n; i != from; i = (i + 1) % n) {
                Player &v = players[i];
                if (v.dead) continue;
                if (v.ident == 2 && v.showed) return i;
                else return -1;
            }
        }
        if (u.ident == 2) {
            for (int i = (from + 1) % n; i != from; i = (i + 1) % n) {
                Player &v = players[i];
                if (v.dead) continue;
                if (v.ident != 2 && v.showed) return i;
                else return -1;
            }
        }
        return -1;
    }

    int findFight(int from) {
        Player &u = players[from];
        if (u.ident == 0) {
            for (int i = (from + 1) % n; i != from; i = (i + 1) % n) {
                Player &v = players[i];
                if (v.dead) continue;
                if (v.likeF || (v.ident == 2 && v.showed)) return i;
            }
        }
        if (u.ident == 1) {
            for (int i = (from + 1) % n; i != from; i = (i + 1) % n) {
                Player &v = players[i];
                if (v.dead) continue;
                if (v.ident == 2 && v.showed) return i;
            }
        }
        if (u.ident == 2) {
            return 0;
        }
        return -1;
    }

    bool J(int from, int to) { // from 打我 to
        Player &s = players[to];
        if (!s.showed) return false;
        bool flag = false;
        for (int p = from; p != from || !flag; p = (p + 1) % n) {
            Player &t = players[p];
            if (t.dead) continue;
            flag = true;
            if (s.ident != 2 && t.ident == 2) continue;
            if (s.ident == 2 && t.ident != 2) continue;
            auto iter = t.find(6);
            if (iter != t.cards.end()) {
                t.give(iter), t.jump();
                return !Js(p, to);
            }
        }
        return false;
    }

    bool Js(int from, int to) { //
        Player &s = players[from];
        for (int i = (from + 1) % n; i != from; i = (i + 1) % n) {
            Player &t = players[i];
            if (t.dead) continue;
            if (s.ident != 2 && t.ident == 1) continue;
            if (s.ident == t.ident && s.ident == 2) continue;
            if (s.ident == 1 && t.ident != 2) continue;
            auto iter = t.find(6);
            if (iter != t.cards.end()) {
                t.give(iter);
                t.jump();
                return !J(i, to);
            }
        }
        return false;
    }

    bool usability(int from, int t) {
        Player &u = players[from];
        if (t == 0 && u.life < 4) return true;
        if (t == 1 && findKill(from) != -1) return true;
        if (t == 3 && findFight(from) != -1) return true;
        if (t == 4 || t == 5 || t==7) return true;
        return false;
    }

    void turn(int p) {
        Player &u = players[p];
        getCard(p, 2);
        bool c = true;
        while (c) {
            c = false;
            for (auto i = u.cards.begin(); i != u.cards.end(); i++) {
                if (!i->use) continue;
                if (!usability(p, i->type)) continue;
                useCard(p, *i);
                if (u.dead) return;
                i = u.cards.begin() - 1;
                c = true;
            }
        }
        u.useKill = false;
    }

    void lifeReduce(int from, int target) {
        Player &u = players[target];
        u.life--;
        if (u.life == 0) {
            auto iter = u.find(0);
            if (iter == u.cards.end()) die(from, target);
            else u.give(iter), u.life++;
        }
    }

    void kill(int from, int to) {
        Player &u = players[from], &v = players[to];
        if (u.useKill && !u.equipped) return;
        u.jump(), u.likeF = false;
        u.useKill = true;
        if (!v.give(2)) lifeReduce(from, to);
    }

    void fight(int from, int to) {
        Player &u = players[from], &v = players[to];
        u.jump(), u.likeF = false;
        if (J(from, to)) return;
        if (u.ident == 0 && v.ident == 1) {
            lifeReduce(from, to);
            return;
        }
        while (true) {
            if (!v.give(1)) {
                lifeReduce(from, to);
                break;
            }
            if (!u.give(1)) {
                lifeReduce(to, from);
                break;
            }
        }
    }

    void IA(int from, int mode) {
        for (int i = (from + 1) % n; i != from; i = (i + 1) % n) {
            Player &u = players[i];
            if (u.dead) continue;
            if (J(from, i)) continue;
            if (!u.give(mode)) {
                lifeReduce(from, i);
                if (u.ident == 0 && !players[from].showed) players[from].likeF = true;
            }
        }
    }

    void game() {
        int p = -1;
        while (true) {
            p = (p + 1) % n;
            if (players[p].dead) continue;
            turn(p);
        }
    }
};

int main() {
#ifdef LOCALENV
    freopen("temp.in", "r", stdin);
    freopen("temp.out", "w", stdout);
#endif
    Game pig;
    pig.init();
    pig.game();
}