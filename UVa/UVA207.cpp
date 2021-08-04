#include <bits/stdc++.h>

using namespace std;

struct Player {
    string name;
    bool amateur = false;
    int score[4] = {0, 0, 0, 0};
    int DQ = 100;
    int ho36 = 0;
    int ho72 = 0;
};

int main() {
    int kase = 0;
    cin >> kase;
    for (int kas = 0; kas < kase; kas++) {
        if (kas != 0)
            cout << endl;
        double totalReward;
        vector<Player> players;
        cin >> totalReward;
        double part[71];
        for (int i = 0; i < 70; i++) cin >> part[i];
        int n;
        cin >> n;
        getchar();
        for (int i = 0; i < n; i++) {
            Player t;
            string s;
            getline(cin, s);
            s.resize(40);
            t.name = s.substr(0, 20);
            t.amateur = false;
            if (t.name.find('*') != string::npos)
                t.amateur = true;
            t.ho36 = t.ho72;
            for (int j = 0; j < 4; j++) {
                string r = s.substr(20 + 3 * j, 3);
                if (!sscanf(r.c_str(), "%d", &t.score[j])) {
                    t.DQ = j;
                    if (j < 2)
                        t.ho36 = 2147483647;
                    break;
                }
                else {
                    t.ho72 += t.score[j];
                    if (j < 2)
                        t.ho36 += t.score[j];
                }
            }
            if (t.ho36 != 2147483647)
                players.push_back(t);
        }
        sort(players.begin(), players.end(), [](const Player &a, const Player &b) { return a.ho36 < b.ho36; });
        for (int i = 69; i < n; i++) {
            if (i == n - 1 || players[i].ho36 != players[i + 1].ho36) {
                n = i + 1;
                break;
            }
        }
        sort(players.begin(), players.begin() + n, [](const Player &a, const Player &b) {
            if (a.DQ == b.DQ && a.DQ == 100) {
                if (a.ho72 != b.ho72)
                    return a.ho72 < b.ho72;
                return a.name < b.name;
            }
            if (a.DQ == 100 && b.DQ < 100)
                return true;
            if (a.DQ < 100 && b.DQ == 100)
                return false;
            if (a.DQ < 100 && a.DQ == b.DQ) {
                if (a.ho72 != b.ho72)
                    return a.ho72 < b.ho72;
                return a.name < b.name;
            }
            return a.DQ > b.DQ;
        });
        cout << "Player Name          Place     RD1  RD2  RD3  RD4  TOTAL     Money Won" << endl;
        cout << "-----------------------------------------------------------------------" << endl;
        int i = 0, pos = 0;
        while (i < n) {
            if (players[i].DQ != 100) {
                cout << left << setw(31) << players[i].name;
                for (int e = 0; e < players[i].DQ; e++) cout << left << setw(5) << players[i].score[e];
                for (int e = players[i].DQ; e < 4; e++) cout << "     ";
                cout << "DQ" << endl;
                i++;
                continue;
            }
            int j = i;
            int pro = 0;
            bool have_money = false;
            double tot = 0.0;
            for (; j < n && players[i].ho72 == players[j].ho72; j++) {
                if (!players[j].amateur) {
                    pro++;
                    if (pos < 70) {
                        have_money = true;
                        tot += part[pos++];
                    }
                }
            }
            int rank = i + 1;
            double reward = totalReward * tot / pro;
            for (; i < j; i++) {
                cout << left << setw(21) << players[i].name;
                string g = to_string(rank);
                if (pro > 1 && have_money && !players[i].amateur)
                    g += "T";
                cout << left << setw(10) << g;
                for (int e : players[i].score) cout << left << setw(5) << e;
                if (!players[i].amateur && have_money) {
                    cout << left << setw(10) << players[i].ho72;
                    cout << "$";
                    cout << right << setw(9) << fixed << setprecision(2) << reward / 100.0 << endl;
                }
                else
                    cout << players[i].ho72 << endl;
            }
        }
    }
    return 0;
}
