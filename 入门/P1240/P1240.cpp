#include <bits/stdc++.h>

using namespace std;

int n;
vector<int>num;
vector<int>dist;

int main() {
	cin >> n;
	int t;
	for (int i = 0; i < n; i++) {
		cin >> t;
		num.push_back(t);
	}
	sort(num.begin(), num.end());
	num.erase(unique(num.begin(), num.end()), num.end());
	for (int i = 0; i < num.size(); i++) {
		dist.push_back(0);
		auto iter = next(num.begin(), i);
		for (int j = num[i];iter!=num.end(); j++,iter++) {
			if (j == *iter)dist.back()++;
			else break;
		}
	}
	sort(dist.begin(), dist.end());
	cout << dist.back() << endl;
	return 0;
}
