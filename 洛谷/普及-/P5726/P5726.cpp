#include <bits/stdc++.h>

using namespace std;

int main() {
    int n;
    int t;
    cin >> n;
    vector<int> x;
    for (int i = 1; i <= n; i++) {
        cin >> t;
        x.push_back(t);
    }
    sort(x.begin(), x.end());
    x.erase(x.begin());
    x.erase(x.end() - 1);
    double sum = 0;
    for (unsigned i = 0; i < x.size(); i++) {
        sum += x[i];
    }
    sum /= double(x.size());
    cout << fixed << setprecision(2) << sum << endl;
    return 0;
}
