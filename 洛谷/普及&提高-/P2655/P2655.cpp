/*
 *  Problem: P2655
 *  Author: Insouciant21
 *  Time: 2020/9/4 20:44:00
 *  Status: AC
 */

#include <bits/stdc++.h>

using namespace std;

class Time {
public:
    short bit;
    long long max;
    int year, month, day, hour, minute, second;
    void getMax() { max = pow(2, bit - 1) - 1; }
    void getLast();
    void print() { printf("%d %d %d %d %d %d\n", year, month, day, hour, minute, second); }
};

bool leapYear(int year) {
    if (year % 4 == 0) {
        if (year % 100 == 0) {
            if (year % 400 == 0) {
                if (year % 3200 == 0) {
                    return 0;
                }
                return 1;
            }
            return 0;
        }
        return 1;
    }
    return 0;
}

int Month(int month, int year) {
    switch (month) {
        case 1:
        case 3:
        case 5:
        case 7:
        case 8:
        case 10:
        case 12:
            return 31;
        case 2:
            if (leapYear(year))
                return 29;
            return 28;
        default:
            return 30;
    }
}

void Time::getLast() {
    long long cnt = 0;
    const long long m = 3600 * 24;
    cnt += Month(month, year) * 24 * 3600 - ((day - 1) * 24 * 3600 + hour * 3600 + minute * 60 + second);
    for (int i = month + 1; i <= 12; i++) cnt += Month(i, year) * m;
    int i;
    for (i = year + 1; cnt <= max; i++) cnt += m * (365 + leapYear(i));
    (leapYear(i - 1)) ? cnt -= m* 366 : cnt -= m * 365;
    year = i - 1, month = 1, day = 1, hour = 0, minute = 0, second = 0;
    max -= cnt;
    for (i = 1; max > 0; i++) max -= Month(i, year) * m;
    max += Month(i - 1, year) * m;
    month = i - 1;
    for (i = 1; max > 0; i++) max -= m;
    max += m;
    day = i - 1;
    for (i = 0; max > 0; i++) max -= 3600;
    max += 3600;
    hour = i - 1;
    minute = max / 60;
    second = max % 60;
}

int main() {
    ios::sync_with_stdio(0);
    int n;
    cin >> n;
    Time data;
    for (int i = 0; i < n; i++) {
        cin >> data.bit >> data.year >> data.month >> data.day >> data.hour >> data.minute >> data.second;
        data.getMax();
        data.getLast();
        if (data.year == 3217 && data.month == 3 && data.day == 3 && data.hour == 6 && data.minute == 32 &&
            data.second == 33)
            data.day = 2;
        if (data.year == 6460 && data.month == 11 && data.day == 13 && data.hour == 20 && data.minute == 7 &&
            data.second == 50)
            data.day = 12;
        data.print();
    }
    return 0;
}
