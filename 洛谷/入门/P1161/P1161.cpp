#include <bits/stdc++.h>

using namespace std;

struct oper {
    double a;
    long long t;
};

bool light[2000001] = { false };
int n;

int main() {
    cin >> n;
    vector<oper> p;
    oper t;
    for (int i = 0; i < n; i++) {
        cin >> t.a >> t.t;
        p.push_back(t);
    }
    for (int x = 0; x < n; x++) {
        for (int i = 1; i <= p[x].t; i++) {
            light[int(i * p[x].a)] = !light[int(i * p[x].a)];
        }
    }
    for (int i = 1; i <= 2000000; i++) {
        if (light[i]) {
            cout << i << endl;
            break;
        }
    }
    return 0;
}
