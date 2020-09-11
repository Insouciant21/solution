#include <iostream>

using namespace std;

int main() {
	int n;
	cin >> n;
	int *m = new int[n + 1];
	bool *result = new bool[n + 1];
	for (int i = 1; i <= n; i++) {
		cin >> m[i];
		if (m[i] % 2 == 0)result[i] = 0;
		else result[i] = 1;
	}
	for (int i = 1; i <= n; i++) {
		if (result[i])cout << "zs wins" << endl;
		else cout << "pb wins" << endl;
	}
	return 0;
}