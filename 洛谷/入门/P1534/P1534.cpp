#include <bits/stdc++.h>

using namespace std;

int n;

int main() {
    int a, b;
    int ang = 0, unh = 0;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> a >> b;
        ang += a + b - 8;
        unh += ang;
    }
    cout << unh << endl;
    return 0;
}
