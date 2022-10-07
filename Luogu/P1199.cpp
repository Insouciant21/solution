#include <bits/stdc++.h>

using namespace std;

int main() {
#ifdef LOCALENV
    freopen("test.in", "r", stdin);
    freopen("test.out", "w", stdout);
#endif
    uniform_int_distribution<int> g(0, 2147482647);
    mt19937 s(random_device {}());
    cout << ((g(s) % 2) ? "0" : "1") << endl;
    return 0;
}