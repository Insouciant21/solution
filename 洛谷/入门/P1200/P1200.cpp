#include <bits/stdc++.h>

using namespace std;

string n_star, n_team;
int star = 1, team = 1;

int main() {
	cin >> n_star >> n_team;
	for (unsigned long long i = 0; i < n_star.length(); i++) {
		star = star * (int(n_star.at(i)) - 64);
	}
	for (unsigned long long i = 0; i < n_team.length(); i++) {
		team = team * (int(n_team.at(i)) - 64);
	}
	if (star % 47 == team % 47) cout << "GO" << endl;
	else cout << "STAY" << endl;
	return 0;
}
