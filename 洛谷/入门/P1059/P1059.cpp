#include <bits/stdc++.h>

using namespace std;

int main() {
    int n, t;
    cin >> n;
    vector<int> m;
    for (int i = 0; i < n; i++) {
        cin >> t;
        m.push_back(t);
    }
    sort(m.begin(), m.end());
    vector<vector<int>::iterator> num;
    num.push_back(m.begin());
    int cnt;
    for (unsigned long long i = 1; i < m.size(); i++)
        if (m[i] != m[i - 1])
            num.push_back(m.begin() + i);
    cnt = num.size();
    cout << cnt << endl;
    for (auto iter = num.begin(); iter != num.end(); iter++) {
        cout << *(*iter) << " ";
    }
    return 0;
}
