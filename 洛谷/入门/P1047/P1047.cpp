
#include <bits/stdc++.h>

using namespace std;

struct pos {
	long long start, end;
};

int main() {
	vector<bool>n;
	long long l, m;
	pos t;
	vector<pos>p;
	cin >> l >> m;
	for (int i = 0; i <= l; i++) n.push_back(true);
	for (int i = 0; i < m; i++) {
		cin >> t.start >> t.end;
		p.push_back(t);
	}
	for (int x = 0; x < m; x++) {
		for (int i = p[x].start; i <= p[x].end; i++) {
			n[i] = false;
		}
	}
	int cnt=0;
	for (auto iter = n.begin(); iter != n.end(); iter++) {
		if (*iter)cnt++;
	}
	cout << cnt << endl;
	return 0;
}
