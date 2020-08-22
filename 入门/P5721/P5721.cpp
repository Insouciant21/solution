#include <bits/stdc++.h>

using namespace std;

int n;

int main() {
    cin >> n;
    int index = 1;
    int last = n * (n + 1) / 2;
    int col = 1;
    while (index <= last) {
        cout << setw(2) << setfill('0') << index;
        index++;
        col++;
        if (col > n) {
            n--;
            col = 1;
            cout << endl;
        }
    }
    return 0;
}
