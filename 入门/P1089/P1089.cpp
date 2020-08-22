#include <bits/stdc++.h>

using namespace std;

int m[13];

int main() {
	int money = 0, bank = 0;
	for (int i = 1; i <= 12; i++) {
		cin >> m[i];
	}
	for (int i = 1; i <= 12; i++) {
		money += 300;
		if (money - m[i] >= 100) {
			bank += (money - m[i]) / 100 * 100;
			money = (money - m[i]) % 100;
		}
		else {
			money -= m[i];
		}
		if (money < 0) {
			cout << "-" << i << endl;
			return 0;
		}
	}
	cout << bank * (1.0 + 0.2) + money << endl;
	return 0;
}
