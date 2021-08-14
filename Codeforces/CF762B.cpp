/*
  Problem: CF762B
  Time: 2020/10/02 15:14:36
  Author: Insouciant21
  Status: Accepted
*/

#include <bits/stdc++.h>

using namespace std;

struct Mouse {
    int price;
    int type;
};

bool operator>(Mouse x, Mouse y) {
    return x.price > y.price;
}

priority_queue<Mouse, vector<Mouse>, greater<Mouse>> v, rem;

int m;
long long a, b, c;
long long cost;

long long e1, e2, e3;

int main() {
    scanf("%I64d %I64d %I64d", &a, &b, &c);
    scanf("%d", &m);
    for (int i = 1; i <= m; i++) {
        int t;
        string x;
        cin >> t >> x;
        if (x == "USB") v.push({t, 1});
        else v.push({t, 0});
    }
    while (v.size()) {
        Mouse prs = v.top();
        if (prs.type == 1 && e1 != a) {
            e1++;
            cost += prs.price;
        }
        else rem.push(prs);
        v.pop();
    }
    while (rem.size()) {
        Mouse prs = rem.top();
        if (e2 != b && !prs.type) {
            e2++;
            cost += prs.price;
        }
        else if (e3 != c) {
            e3++;
            cost += prs.price;
        }
        if (e3 + e2 == b + c) break;
        rem.pop();
    }
    printf("%I64d %I64d\n", e1 + e2 + e3, cost);
    return 0;
}