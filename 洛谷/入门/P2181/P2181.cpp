#include <iostream>
#include <iomanip>

using namespace std;

int main() {
    double n, result;
    cin >> n;
    result = n * (n - 1) * (n - 2) * (n - 3) / 24;
    cout << setiosflags(ios::fixed) << setprecision(0);
    cout << result << endl;
    return 0;
}
