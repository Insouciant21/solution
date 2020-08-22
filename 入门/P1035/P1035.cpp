#include <iostream>

using namespace std;

int main() {
	long long n = 0, k;
	cin >> k;
	double sum=0.00;
	for (int i = 1; sum <= k; i++) {
		sum += 1.00 / i;
		n++;
	}
	cout << n << endl;
	return 0;
}
