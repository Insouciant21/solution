#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    int l;
    cin >> l;
    while (l--) {
        int D, I;
        cin >> D >> I;
        int pos = 1;
        for (int i = 1; i < D; i++) {
            pos = pos * 2 + !(I % 2);
            I = ceil(I / 2.0);
        }
        cout << pos << endl;
    }
    return 0;
}
