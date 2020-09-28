/*
  Problem: P2104
  Time: 2020/09/26 18:05:09
  Author: Insouciant21
  Status: Accepted
*/

#include <bits/stdc++.h>

using namespace std;
vector<int> num;
long long n, m;

void add(int place) {
    num[place]++;
    if (num[place] == 2) {
        num[place] = 0;
        add(place - 1);
    }
    return;
}

void reduce(int place) {
    num[place]--;
    if (num[place] == -1) {
        num[place] = 1;
        reduce(place - 1);
    }
    return;
}

int main() {
    ios::sync_with_stdio(false);
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        char a;
        cin >> a;
        num.push_back(a - '0');
    }
    for (int i = 0; i < m; i++) {
        char oper;
        cin >> oper;
        switch (oper) {
            case '+':
                add(num.size() - 1);
                break;
            case '-':
                reduce(num.size() - 1);
                break;
            case '*':
                num.push_back(0);
                break;
            case '/':
                num.pop_back();
                break;
            default:
                break;
        }
    }
    for_each(num.begin(), num.end(), [](int x) { cout << x; });
    cout << endl;
    return 0;
}