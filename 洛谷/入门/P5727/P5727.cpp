#include <bits/stdc++.h>

using namespace std;

int main() {
	int n;
	vector<int>q;
	cin >> n;
	q.push_back(n);
	while (n != 1) {
		if (n % 2 == 0) n /= 2;
		else n = n * 3 + 1;
		q.push_back(n);
	}
	cout << q.back();
	for (int i = q.size() - 2; i >= 0; i--) cout << " " << q[i];
	return 0;
}
