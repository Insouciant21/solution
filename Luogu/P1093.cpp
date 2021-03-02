/*
  Problem: P1093
  Time: 2021/01/27 20:26:43
  Author: Insouciant21
  Status: Accepted
*/

#include <bits/stdc++.h>

using namespace std;

struct Student {
    string name;
    int year, month, day;
    int id;
};

vector<Student> p;

int main() {
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        Student k;
        cin >> k.name >> k.year >> k.month >> k.day;
        k.id = i;
        p.push_back(k);
    }
    sort(p.begin(), p.end(), [](Student x, Student y) {
        if (x.year >= y.year) {
            if (x.year > y.year)
                return false;
            else {
                if (x.month >= y.month) {
                    if (x.month > y.month)
                        return false;
                    else {
                        if (x.day >= y.day) {
                            if (x.day > y.day)
                                return false;
                            else
                                return x.id > y.id;
                        }
                        return true;
                    }
                }
                return true;
            }
        }
        return true;
    });
    for (int i = 0; i < n; i++) {
        cout << p[i].name << endl;
    }
    return 0;
}