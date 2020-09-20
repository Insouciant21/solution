#include <iostream>

using namespace std;

int main() {
    long long n, i = 0, j = 0;
    cin >> n;
    while (n > j) {
        i++;
        j += i;
    }
    long long x = n + i - j, a, b;

    if (j % 2 == 0) {
        a = x;
        b = i - a;
    } else {
        b = x;
        a = i - b;
    }
    cout << a << "/" << b << endl;
    return 0;
}
