/*
*	Problem: P1835
*	Author: Insouciant21
*	Time: 2020/8/25 13:08:38
*/

#include <bits/stdc++.h>

using namespace std;

bitset<10000000>numlist;
int prime[10000000];

void work(int n) {
	int cnt = 0;
	for (int i = 2; i < n; i++)
	{
		if (!numlist[i])
			prime[cnt++] = i;
		for (int j = 0; j < cnt && i * prime[j] < n; j++)
		{
			numlist[i * prime[j]] = 1;
			if (i % prime[j] == 0)
				break;
		}
	}
}

int main() {
	int L, R;
	ios::sync_with_stdio(0);
	cin >> L >> R;
	int ans = 0;
	work(R);
	for (int i = L; i <= R; i++) {
		if (numlist[i]) ans++;
	}
	cout << ans << endl;
    return 0;
}
