#include <bits/stdc++.h>

using namespace std;

vector<long long>q;

int main() {
	int n, m, k;
	long long t;
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		cin >> t;
		q.push_back(t);
	}
	int cnt = 0;
	long long ans = 0;
	while (!q.empty())
	{
		if (ans + q.front() > m) {
			cnt++;
			ans = 0;
		}
		if (ans + q.front() <= m) {
			ans += q.front();
			q.erase(q.begin());
		}
	}
	cout << cnt + 1 << endl;
	return 0;
}
