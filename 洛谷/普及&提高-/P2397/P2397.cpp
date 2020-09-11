/*
*  Problem: P2397
*  Author: Insouciant21
*  Time: 2020/9/6 19:25:19
*  Status: Accepted
*/

#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(0);
	int n, ans = 0, cnt = 0;
	cin >> n;
	for (int i = 0, t; i < n && cin >> t; i++) {
		if (cnt == 0) {
			ans = t;
			cnt = 1;
		}
		else {
			if (ans == t) cnt++;
			else cnt--;
		}
	}
	cout << ans << endl;
	return 0;
}
