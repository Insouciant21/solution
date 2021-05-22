/*
  Problem: P1015
  Time: 2021/5/22 13:34
  Author: Insouciant21
  Status: Accepted
*/

#include <bits/stdc++.h>

using namespace std;

int n;
string t;
vector<int> m;
map<char, int> value;

bool p(const vector<int> &x) {
    vector<int> y(x);
    reverse(y.begin(), y.end());
    if (x == y)
        return true;
    return false;
}

vector<int> s(vector<int> k) {
    vector<int> g(k);
    reverse(g.begin(), g.end());
    for (int i = 0; i < k.size(); i++)
        k[i] = k[i] + g[i];
    for (int i = k.size() - 1; i > 0; i--) {
        k[i - 1] = k[i - 1] + k[i] / n;
        k[i] = k[i] % n;
    }
    if (k[0] >= n) {
        k[0] = k[0] % n;
        k.insert(k.begin(), 1);
    }
    return k;
}

int main() {
    cin >> n >> t;
    for (char i = '0'; i <= '9'; i++)
        value[i] = i - '0';
    for (char i = 'A'; i <= 'F'; i++)
        value[i] = i - 'A' + 10;
    for (char &i : t)
        m.push_back(value[i]);
    if (p(m)) {
        printf("STEP=0");
        return 0;
    }
    for (int i = 1; i <= 30; i++) {
        m = s(m);
        if (p(m)) {
            printf("STEP=%d", i);
            return 0;
        }
    }
    printf("Impossible!");
    return 0;
}
