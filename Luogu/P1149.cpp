/*
  Problem: P1149
  Time: 2021/5/29 12:29
  Author: Insouciant21
  Status: Accepted
*/

#include <bits/stdc++.h>

using namespace std;

int num[10] = {6, 2, 5, 5, 4, 5, 6, 3, 7, 6};

int ans;

int numOfMatches(int n) {
    int sum = 0;
    string k = to_string(n);
    for (auto &i : k) {
        sum += num[i - '0'];
    }
    return sum;
}

int main() {
    int n;
    cin >> n;
    for (int i = 0; i <= 1000; i++) {
        for (int j = 0; j <= 1000; j++) {
            int k = i + j;
            if (numOfMatches(i) + numOfMatches(j) + numOfMatches(k) + 4 == n)
                ans++;
        }
    }
    cout << ans << endl;
    return 0;
}
