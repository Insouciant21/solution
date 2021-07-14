/*
  Problem: CF1101B
  Time: 2020/10/11 10:23:19
  Author: Insouciant21
  Status: Accepted
*/

#include <bits/stdc++.h>

using namespace std;

string q;

int main() {
    cin >> q;
    int len = q.size();
    int rem = 0;
    while (!q.empty() && q.front() != '[') {
        q.erase(0, 1);
        rem++;
    }
    if (q.empty()) {
        puts("-1");
        return 0;
    }
    while (!q.empty() && q.back() != ']') {
        q.pop_back();
        rem++;
    }
    if (q.empty()) {
        puts("-1");
        return 0;
    }
    while (q.size() != 2 && q[1] != ':') {
        q.erase(1, 1);
        rem++;
    }
    if (q.size() == 2) {
        puts("-1");
        return 0;
    }
    while (q.size() != 3 && *(q.end() - 2) != ':') {
        q.erase(q.size() - 2, 1);
        rem++;
    }
    if (q.size() == 3) {
        puts("-1");
        return 0;
    }
    for (int i = 2; i < q.length() - 2; i++) {
        if (q[i] != '|')
            rem++;
    }
    cout << len - rem << endl;
    return 0;
}