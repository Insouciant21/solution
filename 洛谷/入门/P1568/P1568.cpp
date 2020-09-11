#include <bits/stdc++.h>

using namespace std;

int m, n;
vector<int>sh;
vector<int>kc;
vector<bool>byd;

int main() {
	scanf("%d %d", &m, &n);
	int v, t;
	int time = 0;
	for (int i = 0; i < m; i++) {
		scanf("%d %d", &v, &t);
		for (int j = 1; j <= t; j++) {
			sh.push_back(v);
		}
		time += t;
	}
	for (int i = 0; i < n; i++) {
		scanf("%d %d", &v, &t);
		for (int j = 1; j <= t; j++) {
			kc.push_back(v);
		}
	}
	int cnt = 0;
	int s = 0, l = 0;
	byd.push_back(sh[0] > kc[0]);
	for (int i = 0; i < time; i++) {
		s += sh[i];
		l += kc[i];
		byd.push_back(s > l);
		if (byd.back() != *(byd.end() - 2))cnt++;
	}
	cout << cnt << endl;
	return 0;
}
