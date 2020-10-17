/*
  Problem: CF26B
  Time: 2020/10/16 21:16:56
  Author: Insouciant21
  Status: Accepted
*/

#include <bits/stdc++.h>

using namespace std;

int l;
int ans;
string in;

int main() {
    cin >> in;
    for (int i = 0; i < in.length(); i++) {
        if (in[i] == '(')
            l++;
        else if (l > 0)
            l--, ans += 2;
    }
    cout << ans << endl;
    return 0;
}