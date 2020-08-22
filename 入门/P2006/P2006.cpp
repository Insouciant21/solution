#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int k, m, n;

class skill {
public:
	int id;
	int mana;
	int attack;
	bool canBeDowned(int n);
};

bool skill::canBeDowned(int n) {
	if (mana == 0)return true;
	if (attack * (k / mana) < n) return false;
	else return true;
}

vector<skill>ability;

int main() {
	cin >> k >> m >> n;
	skill tmp;
	for (int i = 0; i < m; i++) {
		cin >> tmp.mana;
		cin >> tmp.attack;
		tmp.id = i + 1;
		ability.push_back(tmp);
	}
	int cnt = 0;
	for (int i = 0; i < m; i++) {
		if (ability[i].canBeDowned(n)) {
			if (i != m - 1)
			{
				cout << ability[i].id << " "; cnt++;
			}
			else cout << ability[i].id << endl;
		};
	}
	if (cnt == 0)cout << -1 << endl;
	return 0;
}
