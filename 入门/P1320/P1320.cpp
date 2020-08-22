#include <bits/stdc++.h>

using namespace std;

int n;
string pic;
vector<int>code;

int main() {
	string t;
	cin >> pic;
	n = pic.length();
	for (int i = 1; i < n; i++) {
		cin >> t;
		pic += t;
	}
	string::iterator iter = pic.begin() + 1;
	code.push_back(1);
	while (iter != pic.end()) {
		if (*iter == *(iter - 1)) {
			code.back()++;
		}
		if (*iter != *(iter - 1)) {
			code.push_back(1);
		}
		iter++;
	}
	cout << n;
	if (pic[0] == '1')cout << " " << 0;
	for (auto i = code.begin(); i != code.end(); i++) {
		cout << " " << *i;
	}
}
