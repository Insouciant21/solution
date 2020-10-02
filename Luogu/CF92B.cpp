/*
  Problem: CF92B
  Time: 2020/10/02 09:54:43
  Author: Insouciant21
  Status: Accepted
*/

#include <bits/stdc++.h>

using namespace std;

vector<int> num;
int ans;

void add(int p) {
    num[p]++;
    if (num[p] == 2 && p != 0) {
        num[p] = 0;
        add(p - 1);
    }
    else if (num[p] == 2 && p == 0) {
        num[p] = 0;
        num.insert(num.begin(), 1);
    }
    return;
}

int main() {
    string x;
    cin >> x;
    for (int i = 0; i < x.length(); i++) num.push_back(x[i] - '0');
    while (num.size() != 1) {
        if (num.back() == 1)
            add(num.size() - 1);
        else
            num.pop_back();
        ans++;
    }
    cout << ans << endl;
    return 0;
}