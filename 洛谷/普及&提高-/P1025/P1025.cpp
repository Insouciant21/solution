/* 
*  Problem: P1025
*  Author: Insouciant21
*  Time: 2020/9/9 18:01:04
*  Status: Accepted
*/

#include <bits/stdc++.h>

using namespace std;

int l;
int k;
int ans;

void dfs(int n, int i, int a) {
	if (i == k) {
		if (n == l) ans++;
		return;
	}
	for (int j = a; n + (k - i) * j <= l; j++)
		dfs(n + j, i + 1, j);
}
int main()
{
	cin >> l >> k;
	dfs(0, 0, 1);
	cout << ans << endl;
	return 0;
}
