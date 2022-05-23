#include <bits/stdc++.h>

using namespace std;

const int inf = 0x3f3f3f;
const double eps = 1e-5;

typedef pair<double, double> pdd;

struct Oil {
    double dist;
    double cost;
};

Oil k[10];

struct Car {
    priority_queue<pair<double, double>, vector<pdd>, greater<pdd>> o;
    double left {};
} f;

int main() {
#ifdef LOCALENV
    freopen("test.in", "r", stdin);
    freopen("test.out", "w", stdout);
#endif
    double c, d, t;
    int n;
    cin >> d >> c >> t >> k[0].cost >> n;
    for (int i = 1; i <= n; i++) cin >> k[i].dist >> k[i].cost;
    k[0].dist = 0;
    k[n + 1].dist = d;
    double ans = 0;
    bool flag = true;
    for (int i = 0; i <= n; i++) {
        vector<pdd> l;
        while (!f.o.empty()) l.push_back(f.o.top()), f.o.pop();
        for (int j = int(l.size() - 1); j >= 0; j--) {
            if (l[j].first > k[i].cost) {
                ans -= l[j].first * l[j].second;
                f.left -= l[j].second;
                l.pop_back();
            }
        }
        while (!l.empty()) f.o.push(l.back()), l.pop_back();
        f.o.push({k[i].cost, c - f.left});
        ans += (c - f.left) * k[i].cost;
        f.left = c;
        double dist = k[i + 1].dist - k[i].dist;
        while (dist > eps && f.left > eps) {
            pdd o = f.o.top();
            f.o.pop();
            if (o.second * t > dist) {
                o.second -= dist / t;
                f.left -= dist / t;
                dist = 0;
                f.o.push(o);
            }
            else {
                dist -= o.second * t;
                f.left -= o.second;
            }
        }
        if (dist > eps && f.left < eps) {
            flag = false;
            break;
        }
    }
    if (!flag) cout << "No Solution" << endl;
    else {
        while (!f.o.empty()) ans -= f.o.top().first * f.o.top().second, f.o.pop();
        cout << fixed << setprecision(2) << ans << endl;
    }
    return 0;
}