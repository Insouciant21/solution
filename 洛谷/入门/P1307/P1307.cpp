#include <bits/stdc++.h>

using namespace std;

int main() {
    int num;
    cin >> num;
    int ans;
    string s = to_string(num);
    if (s[0] == '-') {
        string x = s.substr(1, s.length());
        reverse(x.begin(), x.end());
        ans = stoi(x);
        ans = -ans;
    } else {
        reverse(s.begin(), s.end());
        ans = stoi(s);
    }
    cout << ans << endl;
    return 0;
}
