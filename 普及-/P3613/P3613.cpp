/*
*	Problem: P3613
*	Author: Insouciant21
*	Time: 2020/8/25 14:32:17
*/

#include <bits/stdc++.h>

using namespace std;

class Cube {
public:
	vector<int>grid;
	Cube() { grid.push_back(0); }
	int inquire(int m) {
		return grid[m];
	}
	void save(int j, int k) {
		int gridSize = grid.size() - 1;
		if (gridSize <= j) {
			for (unsigned i = gridSize; i < j - 1; i++) grid.push_back(0);
			grid.push_back(k);
		}
		else grid[j] = k;
	}
};

int main() {

	int n, q;
	cin >> n >> q;
	vector<Cube>cabin(n + 1);
	int operation;
	int wc, wg;
	int savedata;
	for (int i = 0; i < q; i++) {
		cin >> operation;
		if (operation == 1) {
			cin >> wc >> wg >> savedata;
			cabin[wc].save(wg, savedata);
		}
		else {
			cin >> wc >> wg;
			cout << cabin[wc].inquire(wg) << endl;
		}
	}
	return 0;
}
