#include <bits/stdc++.h>

using namespace std;

int main() {
    string s, t;
    ios::sync_with_stdio(false);
    while (cin >> s >> t) {
        int p1[26], p2[26];
        memset(p1, 0, sizeof(p1));
        memset(p2, 0, sizeof(p2));
        for (char &i : s)
            p1[i - 'A']++;
        for (char &i : t)
            p2[i - 'A']++;
        sort(p1, p1 + 26);
        sort(p2, p2 + 26);
        bool find = true;
        for (int i = 0; i < 26; i++) {
            if (p1[i] != p2[i]) {
                cout << "NO" << endl;
                find = false;
                break;
            }
        }
        if (find)
            cout << "YES" << endl;
    }
    return 0;
}
