#include <bits/stdc++.h>

using namespace std;

int main() {
    vector<string> words;
    map<string, vector<int>> p;
    while (true) {
        string t;
        cin >> t;
        if (t == "#") break;
        stringstream ss(t);
        while (ss >> t) {
            words.push_back(t);
            for (auto &i : t) i = char(tolower(i));
            sort(t.begin(), t.end());
            p[t].push_back(int(words.size()));
        }
    }
    set<string> ans;
    for (const auto &i : p) {
        if (i.second.size() > 1) continue;
        ans.insert(words[i.second[0] - 1]);
    }
    for (const auto &i : ans) cout << i << endl;
    return 0;
}
