#include <bits/stdc++.h>
using namespace std;

void handle(vector<string> &s) {
    queue<string> q;

    for (const string &i : s) {
        string t;
        for (auto j : i) {
            t.push_back(j);
            if (j == '<') t.pop_back();
            if (j == '<' && !t.empty()) t.pop_back();
        }
        q.push(t);
    }
    for (int i = 0; i < s.size(); i++) s[i] = q.front(), q.pop();
}

int main() {
    vector<string> s1, s2;
    string s;
    while (true) {
        getline(cin, s);
        if (s == "EOF") break;
        s1.push_back(s);
    }
    while (true) {
        getline(cin, s);
        if (s == "EOF") break;
        s2.push_back(s);
    }
    int T;
    cin >> T;
    handle(s1);
    handle(s2);
    int cnt = 0;
    for (int i = 0; i < min(s1.size(), s2.size()); i++)
        for (int j = 0; j < min(s1[i].length(), s2[i].length()); j++)
            if (s1[i][j] == s2[i][j]) cnt++;
    cout << round(cnt * 60.0 / T) << endl;
}