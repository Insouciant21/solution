/*
  Problem: P1619
  Time: 2020/10/14 20:35:55
  Author: Insouciant21
  Status: Accepted
*/

#include <bits/stdc++.h>

using namespace std;

const int maxn = int(1e7) * 4 + 1;

bitset<maxn> numList;
map<int, int> q;

int prime[2433655];
int cnt;

void prepare() {
    numList[0] = numList[1] = 1;
    for (int i = 2; i < maxn; i++) {
        if (!numList[i]) {
            prime[++cnt] = i;
            for (int j = 2; i * j < maxn; j++)
                numList[i * j] = 1;
        }
    }
}

long long get() {
    string in;
    long long num = 0;
    int cnt = 0;
    getline(cin, in);
    for (int i = 0; i < in.length() && num < maxn; i++) {
        if (in[i] >= '0' && in[i] <= '9') {
            num = num * 10 + (in[i] - '0');
            cnt++;
        }
    }
    if (cnt == 0)
        exit(0);
    return num;
}

int main() {
    prepare();
    ios::sync_with_stdio(false);
    while (true) {
        long long num;
        cout << "Enter the number=";
        num = get();
        long long re = num;
        cout << endl << "Prime? ";
        if (num >= maxn) {
            cout << "No!\n";
            cout << "The number is too large!\n" << endl;
            continue;
        }
        else if (!numList[num]) {
            cout << "Yes!" << endl << endl;
            continue;
        }
        else if (num < 2) {
            cout << "No!\n" << endl;
            continue;
        }
        else
            cout << "No!" << endl;
        for (int i = 1; prime[i] <= num / 2; i++) {
            while (num >= prime[i]) {
                if (num % prime[i] == 0) {
                    q[prime[i]]++;
                    num /= prime[i];
                }
                else
                    break;
            }
        }
        if (num != 1)
            q[num]++;
        string ans;
        for (auto iter = q.begin(); iter != q.end(); iter++) ans += to_string(iter->first) + "^" + to_string(iter->second) + "*";
        ans.pop_back();
        cout << re << "=" << ans << endl << endl;
        q.clear();
    }
    return 0;
}