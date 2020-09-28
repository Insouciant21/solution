/*
  Problem: P5682
  Time: 2020/09/27 20:48:35
  Author: Insouciant21
  Status: Accepted
*/

#include <bits/stdc++.h>

using namespace std;

vector<int> num;
int n;

int main() {
    ios::sync_with_stdio(false);
    cin >> n;
    for (int i = 0; i < n; i++) {
        int t;
        cin >> t;
        num.push_back(t);
    }
    sort(num.begin(), num.end());
    unsigned l = num.size();
    num.erase(unique(num.begin(), num.end()), num.end());
    unsigned x = num.size();
    if (x < 2) {
        puts("-1");
        return 0;
    }
    int m1 = *(num.end() - 3);
    int m2 = num.back() % *(num.end() - 2);
    cout << max(m1, m2) << endl;
    return 0;
}