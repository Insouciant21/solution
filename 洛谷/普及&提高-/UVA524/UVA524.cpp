/*
*  Problem: UVA524
*  Author: Insouciant21
*  Time: 2020/9/16 19:19:38
*  Status: Accepted
*/

#include <bits/stdc++.h>

using namespace std;

bool used[17] = { 0,1 };

int n;

int ans[17] = { 0,1 };

bool prime(int p) {
	if (p < 2) return false;
	for (int i = 2; i <= sqrt(p); i++)
		if (p % i == 0) return false;
	return true;
}

void dfs(int cnt, int last) {
	if (cnt == n + 1 && prime(ans[n] + 1)) {
		for (int i = 1; i < n; i++) cout << ans[i] << " ";
		cout << ans[n] << endl;
		return;
	}
	if (cnt == n + 1) return;
	for (int i = last; i <= n; i += 2) {
		if (used[i]) continue;
		if (!prime(i + ans[cnt - 1])) continue;
		used[i] = 1;
		ans[cnt] = i;
		dfs(cnt + 1, (last % 2 == 0) ? 1 : 2);
		used[i] = 0;
	}
}

int main() {
	int p = 0;
	while (cin >> n) {
		if (p) cout << endl;
		cout << "Case " << ++p << ":\n";
		dfs(2, 2);
	}
	return 0;
}
