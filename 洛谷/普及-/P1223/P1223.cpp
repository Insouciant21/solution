/*
 *	Problem: P1223
 *	Author: Insouciant21
 *	Time: 2020/8/24 15:11:50
 */

#include <bits/stdc++.h>

using namespace std;

struct Wait {
    int time, id;
};

bool cmp(Wait x, Wait y) { return x.time < y.time; }

int main() {
    int n;
    cin >> n;
    ios::sync_with_stdio(false);
    Wait t;
    vector<Wait> wait;
    double average = 0;
    for (int i = 0; i < n; i++) {
        cin >> t.time;
        t.id = i + 1;
        wait.push_back(t);
    }
    sort(wait.begin(), wait.end(), cmp);
    for (int i = 0; i < n; i++) {
        (i == 0) ? cout << wait[i].id : cout << " " << wait[i].id;
        for (int j = 0; j < i; j++) {
            average += wait[j].time;
        }
    }
    average /= n;
    cout << endl << fixed << setprecision(2) << average;
    return 0;
}
