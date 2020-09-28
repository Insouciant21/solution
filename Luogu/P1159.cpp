/*
 *  Problem: P1159
 *  Author: Insouciant21
 *  Time: 2020/9/5 11:00:34
 *  Status: AC
 */

#include <bits/stdc++.h>

using namespace std;

string name[101], oper;

vector<int> up, down;

int n;
bool same[101];

int main() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> name[i] >> oper;
        if (oper == "UP")
            down.push_back(i);
        if (oper == "DOWN")
            up.push_back(i);
        if (oper == "SAME")
            same[i] = true;
    }
    for (int i = 1; i <= n; i++) {
        if (same[i])
            cout << name[i] << endl;
        else {
            if (!up.empty()) {
                cout << name[up.front()] << endl;
                up.erase(up.begin());
            }
            else if (!down.empty()) {
                cout << name[down.front()] << endl;
                down.erase(down.begin());
            }
        }
    }
    return 0;
}
