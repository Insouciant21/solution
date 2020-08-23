/*
*	Problem: P1042
*	Author: Insouciant21
*	Time: 2020/8/23 15:59:37
*/

#include <bits/stdc++.h>

using namespace std;

vector<string>result_11;
vector<string>result_21;
char t;

int main() {
	long long cnt = 1;
	cin >> t;
	long long hua_11 = 0, ene_11 = 0;
	long long hua_21 = 0, ene_21 = 0;
	if (t == 'W') { hua_11++; hua_21++; }
	else { ene_11++; ene_21++; }
	while (t != 'E') {
		cin >> t;
		cnt++;
		if (t == 'W') { hua_11++; hua_21++; }
		else if (t == 'L') { ene_11++; ene_21++; }
		if (hua_11 + ene_11 >= 11 && abs(hua_11 - ene_11) >= 2) {
			result_11.push_back(to_string(hua_11) + ":" + to_string(ene_11));
			hua_11 = 0; ene_11 = 0;
		}
		if (hua_21 + ene_21 >= 21 abs(hua_21 - ene_21) >= 2) {
			result_21.push_back(to_string(hua_21) + ":" + to_string(ene_21));
			hua_21 = 0; ene_21 = 0;
		}
	}
	//if (hua_11 != 0 || ene_11 != 0)
	result_11.push_back(to_string(hua_11) + ":" + to_string(ene_11));
	//if (hua_21 != 0 || ene_21 != 0)
	result_21.push_back(to_string(hua_21) + ":" + to_string(ene_21));
	auto print = [](string a) {cout << a << endl; };
	for_each(result_11.begin(), result_11.end(), print);
	cout << endl;
	for_each(result_21.begin(), result_21.end(), print);
	return 0;
}
