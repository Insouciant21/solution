/*
  Problem: P1010
  Time: 2021/5/22 16:34
  Author: Insouciant21
  Status: Accepted
*/

#include <bits/stdc++.h>

using namespace std;

string ans;

string div(int k) {
    string a;
    while (k) {
        int p = 1, cnt = 0;
        while (p * 2 <= k) {
            p <<= 1;
            cnt++;
        }
        if (cnt == 0) a += "2(0)+";
        if (cnt == 1) a += "2+";
        if (cnt > 1) a += "2(" + div(cnt) + ")+";
        k -= p;
    }
    return a;
}

int main() {
    int n;
    cin >> n;
    ans = div(n);
    for (int i = 0; i < ans.length() - 1; i++) {
        if (ans[i] == '+' && ans[i + 1] == ')') ans[i] = '*';
    }
    ans.pop_back();
    for (auto &i : ans)
        if (i != '*') cout << i;
    cout << endl;
    return 0;
}
