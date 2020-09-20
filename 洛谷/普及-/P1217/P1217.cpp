#include <bits/stdc++.h>

using namespace std;

int a, b;

bool validate(int n) {
    double n_sqrt;
    if (n == 2 || n == 3)
        return 1;
    if (n % 6 != 1 && n % 6 != 5)
        return 0;
    n_sqrt = floor(sqrt((float)n));
    for (int i = 5; i <= n_sqrt; i += 6) {
        if (n % i == 0 || n % (i + 2) == 0)
            return 0;
    }
    return 1;
}

bool palin(int x) {
    if (x < 0 || (x % 10 == 0 && x != 0))
        return false;
    int rev = 0;
    while (x > rev) {
        rev = rev * 10 + x % 10;
        x = int(x / 10);
    }
    return x == rev || x == int(rev / 10);
}

int main() {
    cin >> a >> b;
    b = (b > 10000000) ? 10000000 : b;
    for (int i = a; i <= b; i++) {
        if (palin(i)) {
            if (validate(i))
                cout << i << endl;
        }
    }
    return 0;
}
