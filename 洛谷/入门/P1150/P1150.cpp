#include <bits/stdc++.h>

using namespace std;

int n, k;

void smoke(int x, int y, int &cnt) {
	if (x < y) return;
	cnt = cnt + x / y;
	smoke(x / y + x % y, y, cnt);
}

int main() {
	cin >> n >> k;
	int cnt = n, c = 0;
	smoke(n, k, cnt);
	cout << cnt << endl;
	return 0;
}