#include <bits/stdc++.h>

using namespace std;

int main() {
#ifdef LOCALENV
    freopen("temp.in", "r", stdin);
    freopen("temp.out", "w", stdout);
#endif
    int T;
    cin >> T;
    while (T--) {
        string s;
        cin >> s;
        if (s[0] == 'D' && s[1] == 'X') {
            cout << "yes" << endl;
            continue;
        }
        int cnt = 0;
        char cur;
        bool flag = false;
        for (char i : s) {
            if (cur == i) cnt++;
            else cur = i, cnt = 1;
            if (cnt == 4) {
                flag = true;
                break;
            }
        }
        if (flag) cout << "yes" << endl;
        else cout << "no" << endl;
    }
}
