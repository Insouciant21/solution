/*
  Problem: UVA10474
  Time: 2021/7/14 16:22
  Author: Insouciant21
  Status: AC
*/

#include <bits/stdc++.h>

using namespace std;

int main() {
    int kase = 0;
    int n, q;
    while (cin >> n >> q) {
        if (n == q && n == 0)
            break;
        vector<int> marble;
        for (int i = 0; i < n; i++) {
            int t;
            cin >> t;
            marble.push_back(t);
        }
        sort(marble.begin(), marble.end());
        printf("CASE# %d:\n", ++kase);
        while (q--) {
            int question;
            cin >> question;
            auto p = lower_bound(marble.begin(), marble.end(), question);
            if (*p != question)
                printf("%d not found\n", question);
            else
                printf("%d found at %d\n", question, p - marble.begin() + 1);
        }
    }
    return 0;
}
