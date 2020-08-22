#include <bits/stdc++.h>

using namespace std;

int main() {
    int k;
    cin >> k;
    int index = 1;
    int cnt = 1;
    while (index <= k) {
        index += cnt + 1;
        cnt++;
    }
    index -= cnt;
    cnt--;
    int gold = 0;
    for (int i = 1; i <= cnt; i++) {
        for (int j = 1; j <= i; j++) gold += i;
    }
    for (int i = index; i < k; i++) {
        gold += (cnt + 1);
    }
    cout << gold << endl;
    return 0;
}
