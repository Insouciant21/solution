/*
 *  Problem: P2952
 *  Author: Insouciant21
 *  Time: 2020/9/7 18:11:36
 *  Status: Accepted
 */

#include <bits/stdc++.h>

using namespace std;

deque<int> cow;
int n;

int main() {
    ios::sync_with_stdio(false);
    cin >> n;
    char o1, o2;
    int k;
    int cnt = 1;
    for (int i = 1; i <= n; i++) {
        cin >> o1 >> o2;
        if (o1 == 'A') {
            if (o2 == 'L')
                cow.push_front(cnt);
            else
                cow.push_back(cnt);
            cnt++;
        } else {
            cin >> k;
            if (o2 == 'L')
                for (int j = 1; j <= k; j++) cow.pop_front();
            else
                for (int j = 1; j <= k; j++) cow.pop_back();
        }
    }
    while (!cow.empty()) {
        cout << cow.front() << endl;
        cow.pop_front();
    }
    return 0;
}
