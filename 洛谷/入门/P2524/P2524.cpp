#include <iostream>
#include <vector>

using namespace std;

const int fac[] = { 1, 1, 2, 6, 24, 120, 720, 5040, 40320, 362880 };

int cantor(int num) {
	int ans = 0;
	vector <int> a;
	while (num != 0) {
		a.push_back(num % 10);
		num /= 10;
	}
	for (int i = 0; i < a.size(); i++) {
		int cnt = 0;
		for (int j = i - 1; j >= 0; j--)
			if (a[i] > a[j])
				cnt++;
		ans += fac[i] * cnt;
	}
	return ans + 1;
}

int main() {
	int N, X;
	cin >> N >> X;
	cout << cantor(X) << endl;
}