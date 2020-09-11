/*
*	Problem: P5740
*	Author: Insouciant21
*	Time: 2020/8/22 22:07:12
*/

#include <bits/stdc++.h>

using namespace std;

struct score {
	string name;
	int chi, math, eng;
	int total;
	bool operator<(score p) {
		return total < p.total;
	}
	bool operator!=(score p) {
		return chi != p.chi || math != p.math || eng != p.eng;
	}
	bool operator==(score p) {
		return chi == p.chi && math == p.math && eng == p.eng;
	}
	bool operator>(score p) {
		return total > p.total;
	}
	void show() {
		printf("%s %d %d %d\n", name.c_str(), chi, math, eng);
	}
};

int main() {
	int n;
	cin >> n;
	vector<score>q;
	score t;
	for (int i = 0; i < n; i++) {
		cin >> t.name >> t.chi >> t.math >> t.eng;
		t.total = t.chi + t.math + t.eng;
		q.push_back(t);
	}
	stable_sort(q.begin(), q.end(), [](score a, score b) {return a.total < b.total; });
	q.erase(unique(q.begin(), q.end()), q.end());
	q.back().show();
	return 0;
}