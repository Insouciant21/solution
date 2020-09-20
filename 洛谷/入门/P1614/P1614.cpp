#include <bits/stdc++.h>

using namespace std;

int n, m;
vector<int> q, sum;

int main() {
    scanf("%d %d", &n, &m);
    int t;
    for (int i = 1; i <= n; i++) {
        scanf("%d", &t);
        q.push_back(t);
    }
    if (n == m) {
        int sum = 0;
        for (int i = 0; i < n; i++) {
            sum += q[i];
        }
        cout << sum;
        return 0;
    }
    for (int i = 0; i < q.size() - m; i++) {
        sum.push_back(0);
        for (int j = i; j < i + m; j++) {
            sum.back() += q[j];
        }
    }
    cout << *min_element(sum.begin(), sum.end());
    return 0;
}
