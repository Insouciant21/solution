#include <bits/stdc++.h>

using namespace std;

int main() {
	string sub;
	int  sub1, sub2, sub3;
	int K;
	bool x = false;
	cin >> K;
	for (int i = 10000; i <= 30000; i++) {
		sub = to_string(i);
		sub1 = stoi(sub.substr(0, 3));
		sub2 = stoi(sub.substr(1, 3));
		sub3 = stoi(sub.substr(2, 3));
		if ((sub1 % K == 0) && (sub2 % K == 0) && (sub3 % K == 0)) { cout << i << endl; x = true; }
	}
	if (x) return 0;
	cout << "No";
	return 0;
}
