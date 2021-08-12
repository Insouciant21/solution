#include <bits/stdc++.h>

using namespace std;

set<string> addr;

struct User {
    string name;
    string mta;
};

void splitAddress(const string &a, User &g) {
    size_t pos = a.find('@');
    g.name = a.substr(0, pos);
    g.mta = a.substr(pos + 1);
}

int main() {
    while (true) {
        string t;
        cin >> t;
        if (t == "*") break;
        string name;
        cin >> name;
        int n;
        cin >> n;
        for (int i = 0; i < n; i++) {
            cin >> t;
            t.append("@");
            addr.emplace(t + name);
        }
    }
    while (true) {
        string s;
        cin >> s;
        if (s == "*") break;
        User sender;
        splitAddress(s, sender);
        vector<User> receivers;
        vector<pair<string, vector<int>>> MTAs;
        while (true) {
            cin >> s;
            if (s == "*") break;
            User t;
            splitAddress(s, t);
            bool failure = false;
            for (const auto &i : receivers) {
                if (t.name == i.name && t.mta == i.mta) {
                    failure = true;
                    break;
                }
            }
            if (failure) continue;
            bool find = false;
            for (auto &i : MTAs) {
                if (i.first == t.mta) {
                    find = true;
                    i.second.push_back(int(receivers.size()));
                    break;
                }
            }
            if (!find) {
                MTAs.push_back({t.mta, {int(receivers.size())}});
            }
            receivers.push_back(t);
        }
        vector<string> data;
        getchar();
        while (true) {
            getline(cin, s);
            if (s[0] == '*') break;
            data.push_back(s);
        }
        for (const auto &i : MTAs) {
            printf("Connection between %s and %s\n", sender.mta.c_str(), i.first.c_str());
            printf("     HELO %s\n     250\n", sender.mta.c_str());
            printf("     MAIL FROM:<%s>\n     250\n", (sender.name + "@" + sender.mta).c_str());
            bool hasFound = false;
            for (auto j : i.second) {
                string a = receivers[j].name + "@" + receivers[j].mta;
                printf("     RCPT TO:<%s>\n", a.c_str());
                if (addr.count(a)) hasFound = true, printf("     250\n");
                else printf("     550\n");
            }
            if (hasFound) {
                printf("     DATA\n     354\n");
                for (const auto &j : data)
                    printf("     %s\n", j.c_str());
                printf("     .\n     250\n");
            }
            printf("     QUIT\n     221\n");
        }
    }
    return 0;
}
