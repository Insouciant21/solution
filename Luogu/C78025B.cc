#include <bits/stdc++.h>

using namespace std;

const int MAXN = int(1e7) + 10; // Set a right value according to your solution.
int n;
vector<int> p;
vector<pair<int, int>> a;
map<int, int> m;

namespace Generator {

    unsigned long long k1, k2;
    int thres;

    inline unsigned long long xorShift128Plus() {
        unsigned long long k3 = k1, k4 = k2;
        k1 = k4, k3 ^= (k3 << 23), k2 = k3 ^ k4 ^ (k3 >> 17) ^ (k4 >> 26);
        return k2 + k4;
    }

    inline void generate() {
        for (int i = 0; i < n; ++i) {
            a.emplace_back(xorShift128Plus() % thres, 0);
            p.push_back(a[i].first);
        }
    }

} // namespace Generator.

bool cmp(int f, int b) {
    string x, y;
    x = to_string(f), y = to_string(b);
    for (int i = 0; i < min(x.length(), y.length()); i++)
        if (x[i] > y[i]) return false;
    if (x.length() < y.length()) return true;
    else return false;
}

int main() {
#ifdef LOCALENV
    freopen("temp.in", "r", stdin);
    freopen("temp.out", "w", stdout);
#endif
    scanf("%d", &n);
    scanf("%llu %llu %d", &Generator::k1, &Generator::k2, &Generator::thres);
    Generator::generate();
    p.erase(unique(p.begin(), p.end()), p.end());
    sort(p.begin(), p.end(), cmp);
    for (int i = 0; i < p.size(); i++) m[i] = i;
    for (int i = 0; i < n; i++) a[i].second = m[a[i].first];
    int p1 = 0, p2;
    while (p1 != n) {
        pair<int, int> minx = {a[p1].second, p1};
        p2 = p1 + 1;
        while (p2 != n) {
            if (minx.first >= a[p2].second) minx.first = a[p2].second, minx.second = p2;
            p2++;
        }
        if (minx.second == p1) p1++;
        else {
            swap(a[p1], a[minx.second]);
            p1 = minx.second + 1;
        }
    }
    unsigned long long ans = 0;
    for (int i = 0; i < a.size(); i++) ans += (i + 1) * a[i].first;
    cout << ans << endl;
    return 0;
}