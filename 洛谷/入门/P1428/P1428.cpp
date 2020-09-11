#include <bits/stdc++.h>

using namespace std;

vector<int>cute;
int n;

int main() {
	cin >> n;
	int t;
	for (int i = 0; i < n; i++) {
		cin >> t;
		cute.push_back(t);
	}
	vector<int>ans;
	for (int i = 1; i < cute.size(); i++) {
		ans.push_back(0);
		for (int j = 0; j < i; j++) {
			if (cute[j] < cute[i]) ans.back()++;
		}
	}
	cout << 0;
	for (auto i = ans.begin(); i != ans.end(); i++) {
		cout << " " << *i;
	}
	return 0;
}
