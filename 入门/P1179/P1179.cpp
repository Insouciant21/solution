#include <bits/stdc++.h>

using namespace std;

int L, R;
string str;

int main() {
    cin >> L >> R;
    for (int i = L; i <= R; i++) {
        str += to_string(i);
    }
    cout << count(str.begin(), str.end(), '2');
    return 0;
}
