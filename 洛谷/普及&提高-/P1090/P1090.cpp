/*
*	Problem: P1090
*	Author: Insouciant21
*	Time: 2020/8/24 15:50:44
*/

#include <bits/stdc++.h>

using namespace std;

priority_queue<int, vector<int>, greater<int>>fruit;
int n;

int main() {
    ios::sync_with_stdio(false);
    cin >> n;
    int t;
    for (int i = 0; i < n; i++) {
        cin >> t;
        fruit.push(t);
    }
    int stemia = 0;
    int x, y;
    while (fruit.size() != 1) {
        x = fruit.top();
        fruit.pop();
        y = fruit.top();
        fruit.pop();
        stemia = stemia + x + y;
        fruit.push(x + y);
    }
    cout << stemia << endl;
    return 0;
}
