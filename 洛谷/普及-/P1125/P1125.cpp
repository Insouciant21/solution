#include <bits/stdc++.h>

using namespace std;

bool validate(int x) {
    if (x < 2)
        return false;
    for (int i = 2; i <= sqrt(x); i++)
        if (x % i == 0)
            return false;
    return true;
}

int main() {
    string x;
    cin >> x;
    vector<int> cnt;
    int t;
    for (char i = 'a'; i <= 'z'; i++) {
        t = count(x.begin(), x.end(), i);
        if (t != 0)
            cnt.push_back(t);
    }
    sort(cnt.begin(), cnt.end());
    if (validate(cnt.back() - cnt.front())) {
        cout << "Lucky Word" << endl;
        cout << cnt.back() - cnt.front();
    } else {
        cout << "No Answer" << endl;
        cout << 0 << endl;
    }
    return 0;
}
