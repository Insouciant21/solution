#include <bits/stdc++.h>

using namespace std;

int L;

bool validate(int p) {
    for (int i = 2; i <= sqrt(p); i++) 
        if (p % i == 0) return false;
    return true;
}

int main() {
    cin >> L;
    int sum = 0;
    int cnt = 0;
    for (int i = 2; ; i++) {
        if (validate(i)&&sum<=L) {
            sum += i;
            if (sum > L) break;
            cout << i << endl;
            cnt++;
        }
    }
    cout << cnt << endl;
    return 0;
}
