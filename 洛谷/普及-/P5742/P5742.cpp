/*
*	Problem: P5742
*	Author: Insouciant21
*	Time: 2020/8/22 22:23:07
*/

#include <bits/stdc++.h>

using namespace std;

struct stu {
	int id;
	int score, ext;
	double all;
};

bool validate(stu x) {
	return x.score + x.ext >= 140 && x.all >= 80;
}

int main() {
	int n;
	cin >> n;
	stu t;
	for (int i = 0; i < n; i++) {
		cin >> t.id >> t.score >> t.ext;
		t.all = t.score * 0.7 + t.ext * 0.3;
		if (validate(t)) cout << "Excellent" << endl;
		else cout << "Not excellent" << endl;
	}
	return 0;
}
