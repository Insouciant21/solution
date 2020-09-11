#include <bits/stdc++.h>

using namespace std;

int n;

int main() {
	scanf_s("%d", &n);
	double ans;
	if (n <= 150) {
		ans = 0.4463 * n;
	}
	else if (n > 150 && n <= 400) {
		ans = 0.4463 * 150 + (n - 150) * 0.4663;
	}
	else {
		ans = 0.4463 * 150 + 0.4663 * 250 + (n - 400) * 0.5663;
	}
	cout << setiosflags(ios::fixed) << setprecision(1) << ans << endl;
	return 0;
}
