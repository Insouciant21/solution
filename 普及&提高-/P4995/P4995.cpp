/*
*	Problem: P4995
*	Author: Insouciant21
*	Time: 2020/8/24 16:07:48
*/

#include <bits/stdc++.h>

using namespace std;

int n;
vector<int>stone;

void work(vector<int> &s) {
    int i = 0;
    while (i<s.size()-1)
    {
        s.insert(s.begin() + i, s.back());
        s.pop_back();
        i += 2;
    }
}

long long consume(int x, int y) {
    return (x - y) * (x - y);
}

int main() {
    scanf("%d", &n);
    int t;
    for (int i = 0; i < n; i++) {
        scanf("%d", &t);
        stone.push_back(t);
    }
    sort(stone.begin(), stone.end());
    work(stone);
    long long stamina = 0;
    stone.insert(stone.begin(), 0);
    int where = 0;
    for (int i = 0; i < stone.size() - 1; i++)
        stamina += consume(stone[i], stone[i + 1]);
    cout << stamina << endl;
    return 0;
}
