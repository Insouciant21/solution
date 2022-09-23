#include <bits/stdc++.h>

using namespace std;
const int maxn = int(1e6) + 10;
int n, k;
int a[maxn];

int main() {
#ifdef LOCALENV
    freopen("test.in", "r", stdin);
    freopen("test.out", "w", stdout);
#endif
    cin >> n >> k;
    for (int i = 1; i <= n; i++) cin >> a[i];
    deque<int> minv, maxv;
    for (int i = 1; i < k; i++) {
        while (!minv.empty() && a[i] < a[minv.back()]) minv.pop_back();
        while (!maxv.empty() && a[i] > a[maxv.back()]) maxv.pop_back();
        minv.push_back(i);
        maxv.push_back(i);
    }
    for (int i = k; i <= n; i++) {
        while (!minv.empty() && a[i] < a[minv.back()]) minv.pop_back();
        minv.push_back(i);
        while (minv.front() <= i - k) minv.pop_front();
        cout << minv.front() << " ";
    }
    cout << endl;
    for (int i = k; i <= n; i++) {
        while (!maxv.empty() && a[i] > a[maxv.back()]) maxv.pop_back();
        maxv.push_back(i);
        while (maxv.front() <= i - k) maxv.pop_front();
        cout << maxv.front() << " ";
    }
    return 0;
}