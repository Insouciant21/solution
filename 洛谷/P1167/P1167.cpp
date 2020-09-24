/*
 *  Problem: P1167
 *  Author: Insouciant21
 *  Time: 2020/9/5 11:29:10
 *  Status: AC
 */

#include <bits/stdc++.h>

using namespace std;

priority_queue<int, vector<int>, greater<int>> p;
int n;
long long timer;
int year1, mo1, d1, h1, mi1;
int y2, mo2, d2, h2, mi2;

bool leapYear(int a) {
    if (a % 4 == 0) {
        if (a % 100 == 0) {
            if (a % 400 == 0) {
                return 1;
            }
            return 0;
        }
        return 1;
    }
    return 0;
}

int getDayOfMonth(int x, int y) {
    switch (x) {
        case 1:
        case 3:
        case 5:
        case 7:
        case 8:
        case 10:
        case 12:
            return 31;
        case 2:
            if (leapYear(y))
                return 29;
            return 28;
        default:
            return 30;
    }
}
void remaining() {
    int leap = 0, nLeap = 0;
    for (int i = 0; i < year1; i++) {
        if (leapYear(i))
            leap++;
        else
            nLeap++;
    }
    long long x = leap * 366 * 24 * 60 + nLeap * 365 * 24 * 60;
    for (int i = 1; i < mo1; i++) x += getDayOfMonth(i, year1) * 24 * 60;
    leap = 0, nLeap = 0;
    x += (d1 - 1) * 24 * 60 + h1 * 60 + mi1;
    for (int i = 0; i < y2; i++) {
        if (leapYear(i))
            leap++;
        else
            nLeap++;
    }
    long long y = leap * 366 * 24 * 60 + nLeap * 365 * 24 * 60;
    for (int i = 1; i < mo2; i++) y += getDayOfMonth(i, y2) * 24 * 60;
    y += (d2 - 1) * 24 * 60 + h2 * 60 + mi2;
    timer = y - x;
}

int main() {
    scanf("%d", &n);
    for (int i = 1, t; i <= n; i++) {
        scanf("%d", &t);
        p.push(t);
    }
    scanf("%d-%d-%d-%d:%d", &year1, &mo1, &d1, &h1, &mi1);
    scanf("%d-%d-%d-%d:%d", &y2, &mo2, &d2, &h2, &mi2);
    int cnt = 0;
    long long past = 0;
    remaining();
    while (true) {
        past += p.top();
        if (past > timer)
            break;
        cnt++;
        if (cnt == n)
            break;
        p.pop();
    }
    cout << cnt << endl;
    return 0;
}
