#include <bits/stdc++.h>

using namespace std;

int x, n;

int main() {
	cin >> x >> n;
	int ans = 0;
	int p = x;
	for (int i = x; i < x + n; i++) {
		if (p >= 7)
			p = p % 7;
		if (p != 6 && p != 0) {
			ans += 250;
		}
		p++;

	}
	cout << ans;
	return 0;
}
