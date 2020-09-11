#include <bits/stdc++.h>

using namespace std;

int n;

int main() {
	cin >> n;
	int *jolly = new int[n];
	for (int i = 0; i < n; i++) cin >> jolly[i];
	vector<int>dist;
	for (int i = 0; i < n - 1; i++) {
		dist.push_back(abs(jolly[i] - jolly[i + 1]));
	}
	sort(dist.begin(), dist.end());
	int cnt = 0;
	for (int i = 1; i <= n - 1; i++) {
		if (dist[i - 1] == i) cnt++;
	}
	if (cnt == dist.size())cout << "Jolly" << endl;
	else cout << "Not jolly" << endl;
	return 0;
}
