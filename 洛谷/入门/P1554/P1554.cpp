#include <bits/stdc++.h>

using namespace std;

int m, n;
int cnt[10] = { 0 };

int main() {
    cin >> m >> n;
    string con;
    for (int i = m; i <= n; i++) {
        con = to_string(i);
        cnt[0] += count(con.begin(), con.end(), '0');
        cnt[1] += count(con.begin(), con.end(), '1');
        cnt[2] += count(con.begin(), con.end(), '2');
        cnt[3] += count(con.begin(), con.end(), '3');
        cnt[4] += count(con.begin(), con.end(), '4');
        cnt[5] += count(con.begin(), con.end(), '5');
        cnt[6] += count(con.begin(), con.end(), '6');
        cnt[7] += count(con.begin(), con.end(), '7');
        cnt[8] += count(con.begin(), con.end(), '8');
        cnt[9] += count(con.begin(), con.end(), '9');
    }
    cout << cnt[0];
    for (int i = 1; i <= 9; i++) cout << " " << cnt[i];
    return 0;
}
