#include <bits/stdc++.h>

using namespace std;

int n;
vector<int> temper;
vector<int> cnt;

int main() {
    cin >> n;
    int t;
    cnt.push_back(1);
    for (int i = 0; i < n; i++) {
        cin >> t;
        temper.push_back(t);
        if (i >= 1) {
            if (temper[i] < temper[i - 1])
                cnt.push_back(1);
            else
                cnt.back()++;
        }
    }
    cout << *max_element(cnt.begin(), cnt.end());
    return 0;
}
