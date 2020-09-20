#include <bits/stdc++.h>

using namespace std;

int n, d, ans = 0;
vector<int> pos;

int main() {
    cin >> n >> d;
    int t;
    int c = 1;
    for (int i = 0; i < n; i++) {
        cin >> t;
        pos.push_back(t);
    }
    sort(pos.begin(), pos.end());
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (pos[i] + d > pos[j])
                ans++;
            else
                break;
        }
    }
    cout << ans << endl;
    return 0;
}
