#include <bits/stdc++.h>

using namespace std;

int l;
int ans;
string in;

int main() {
    cin >> in;
    for (char i : in) {
        if (i == '(') l++;
        else if (l > 0) l--, ans += 2;
    }
    cout << ans << endl;
    return 0;
}