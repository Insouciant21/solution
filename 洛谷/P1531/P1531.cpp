/*
 *  Problem: P1531
 *  Author: Insouciant21
 *  Time: 2020/9/4 19:23:24
 */

#include <bits/stdc++.h>

using namespace std;

class Student {
   public:
    int id;
    int score;
    Student(int i, int j) {
        id = i, score = j;
    }
};

vector<Student> stu;

int main() {
    int m, n;
    ios::sync_with_stdio(0);
    cin >> n >> m;
    stu.push_back(Student(0, 0));
    for (int i = 1, t; i <= n; i++) {
        cin >> t;
        stu.push_back(Student(i, t));
    }
    char oper;
    int x, y;
    for (int i = 1; i <= m; i++) {
        cin >> oper >> x >> y;
        if (oper == 'Q') {
            int max = stu[x].score;
            for (int j = x; j <= y; j++)
                if (stu[j].score > max)
                    max = stu[j].score;
            cout << max << endl;
        }
        else if (oper == 'U') {
            if (stu[x].score < y)
                stu[x].score = y;
        }
    }
    return 0;
}
