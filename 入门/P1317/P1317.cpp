#include <bits/stdc++.h>

using namespace std;

int n, ans = 0;
vector<int>height;

int main() {
	int t;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> t; height.push_back(t);
	}
	height.erase(unique(height.begin(), height.end()), height.end());
	for (int i = 1; i < height.size() - 1; i++) {
		if (height[i] < height[i - 1] && height[i] < height[i + 1])ans++;
	}
	cout << ans;
	return 0;
}
