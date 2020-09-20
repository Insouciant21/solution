#include <bits/stdc++.h>

using namespace std;

struct score {
    int chi, math, eng;
    int total;
};

int main() {
    int n;
    cin >> n;
    vector<score> q;
    score t;
    int ans = 0;
    for (int i = 0; i < n; i++) {
        cin >> t.chi >> t.math >> t.eng;
        t.total = t.chi + t.math + t.eng;
        q.push_back(t);
    }
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if (abs(q[i].total - q[j].total) <= 10) {
                if (abs(q[i].chi - q[j].chi) <= 5 && abs(q[i].math - q[j].math) <= 5 &&
                    abs(q[i].eng - q[j].eng) <= 5)
                    ans++;
            }
        }
    }
    cout << ans << endl;
    return 0;
}
