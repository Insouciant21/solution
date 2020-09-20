#include <bits/stdc++.h>

using namespace std;

int main() {
    int n;
    cin >> n;
    int index = 1;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cout << setw(2) << setfill('0') << index;
            index++;
        }
        cout << endl;
    }
    index = 1;
    cout << endl;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n - i; j++) cout << "  ";
        for (int j = 1; j <= i; j++) {
            cout << setw(2) << setfill('0') << index;
            index++;
        }
        cout << endl;
    }
    return 0;
}
