
#include <bits/stdc++.h>

using namespace std;

struct lesson {
	int id;
	long long time;
	long long unhappy;
};

lesson j[7];

int main() {
	int t1, t2;
	for (int i = 0; i < 7; i++) {
		cin >> t1 >> t2;
		j[i].id = i + 1;
		j[i].time = t1 + t2;
		if (j[i].time > 8) {
			j[i].unhappy = j[i].time - 8;
		}
		else j[i].unhappy = 0;
	}
	stable_sort(j, j + 7, [](lesson a, lesson b) {return a.unhappy < b.unhappy; });
	int cnt = 0;
	for (int i = 6; i > 0; i--) {
		if (j[i].unhappy == j[i - 1].unhappy)cnt++;
		if (j[i].unhappy != j[i - 1].unhappy)break;
	}
	cout << j[6 - cnt].id << endl;
	return 0;
}
