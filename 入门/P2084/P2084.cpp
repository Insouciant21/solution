#include <iostream>
#include <string>

using namespace std;

int main() {
	int M; string N;
	int x;
	bool flag = 1;
	cin >> M >> N;
	int len = N.length();
	for (int i = 0; i <len; i++) {
		x = N[i] - '0';
		if (x) {
			if (flag)cout << N[i] << "*" << M << "^" << len-i-1, flag = 0;
			else cout << "+" << N[i] << "*" << M << "^" << len-i-1;
		}
	}
	return 0;
}
