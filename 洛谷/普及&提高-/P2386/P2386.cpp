/*
*  Problem: P2386
*  Author: Insouciant21
*  Time: 2020/9/9 21:35:04
*  Status: Accepted
*/

#include <bits/stdc++.h>

using namespace std;

int n, m;
int ans;

void dfs(int sum, int cnt, int last) {
	if (sum == n && cnt <= m) {
		ans++;
	}
	if (cnt <= m) {
		for (int i = last; i <= n; i++) {
			dfs(sum + i, cnt + 1, i);
		}
	}
}

int main() {
	ios::sync_with_stdio(0);
	int t;
	cin >> t;
	for (int i = 0; i < t; i++) {
		cin >> n >> m;
		dfs(0, 0, 1);
		cout << ans << endl;
		ans = 0;
	}
	return 0;
}
