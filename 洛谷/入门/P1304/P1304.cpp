#include <bits/stdc++.h>

using namespace std;

int n;
vector<int> p;

bool prime(int x) {
    for (int i = 2; i <= sqrt(x); i++) {
        if (x % i == 0)
            return false;
    }
    return true;
}

string split(int a) {
    string ans;
    for (int i = 2; i <= a / 2; i++) {
        if (prime(i) && prime(a - i)) {
            ans = to_string(i) + "+" + to_string(a - i);
            return ans;
        }
    }
    return nullptr;
}

int main() {
    cin >> n;
    for (int i = 4; i <= n; i += 2) {
        cout << i << "=" << split(i) << endl;
    }
    return 0;
}
