#include <bits/stdc++.h>

using namespace std;

int main() {
    string x;
    cin >> x;
    if (x[0] == ')' || x.back() == '(') {
        cout << "NO\n";
        return 0;
    }
    int cnt = 0;
    for (int i = 0; i < x.length(); i++) {
        if (x[i] == '(')
            cnt++;
        if (x[i] == ')')
            cnt--;
        if (cnt < 0) {
            cout << "NO\n";
            return 0;
        }
    }
    if (cnt != 0) {
        cout << "NO\n";
    } else {
        cout << "YES\n";
    }
    return 0;
}
