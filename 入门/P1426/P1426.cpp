#include <bits/stdc++.h>

using namespace std;

double s, x;
char ans;

int main() {
	cin >> s >> x;
	int pos = 0;
	int speed = 7;
	while (pos < s - x) {
		pos += speed;
		speed *= 0.98;
	}
	if (pos + speed < s + x) ans = 'y';
	else ans = 'n';
	cout << ans << endl;
	return 0;
}
