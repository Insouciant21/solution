#include <bits/stdc++.h>

using namespace std;

struct Building {
    double x {}, y {};
    double w {}, d {}, h {};
    int id = 0;
};

vector<Building> g;

bool inLine(int i, double x) {
    return g[i].x <= x && g[i].x + g[i].w >= x;
}

bool canBeSee(int k, double x) {
    if (!inLine(k, x)) return false;
    for (int i = 0; i < g.size(); i++)
        if (inLine(i, x) && g[i].y < g[k].y && g[i].h >= g[k].h) return false;
    return true;
}

int main() {
    int n, kase = 0;
    while (cin >> n && n) {
        if (kase) printf("\n");
        kase++;
        vector<double> xx;
        for (int i = 0; i < n; i++) {
            Building f {};
            cin >> f.x >> f.y >> f.w >> f.d >> f.h;
            f.id = i + 1;
            g.push_back(f);
            xx.push_back(f.x);
            xx.push_back(f.x + f.w);
        }
        sort(g.begin(), g.end(), [](Building a, Building b) { return a.x < b.x || (a.x == b.x && a.y < b.y); });
        sort(xx.begin(), xx.end());
        xx.erase(unique(xx.begin(), xx.end()), xx.end());
        printf("For map #%d, the visible buildings are numbered as follows:\n", kase);
        bool f = false;
        for (int i = 0; i < g.size(); i++) {
            for (int j = 0; j < xx.size() - 1; j++)
                if (canBeSee(i, (xx[j] + xx[j + 1]) / 2)) {
                    printf(f ? " %d" : "%d", g[i].id);
                    f = true;
                    break;
                }
        }
        printf("\n");
        g.clear();
    }
    return 0;
}
