/*
*	Problem: P1042
*	Author: Insouciant21
*	Time: 2020/8/23 15:59:37
*/

#include <bits/stdc++.h>

using namespace std;

bool situation[62501];

int main() {
	char s;
	int cnt = 0;
	for (int i = 1; cin >> s && s != 'E'; i++) {
		if (s == 'W') situation[i] = 1;
		else situation[i] = 0;
		cnt++;
	}
	int win = 0, lost = 0;
	for (int i = 1; i <= cnt; i++) {
		if (situation[i]) win++;
		else lost++;
		if (win >= 11 || lost >= 11) {
			if (abs(win - lost) >= 2) {
				printf("%d:%d\n", win, lost);
				win = 0, lost = 0;
			}
		}
	}
	printf("%d:%d\n", win, lost);
	printf("\n");
	win = 0, lost = 0;
	for (int i = 1; i <= cnt; i++) {
		if (situation[i]) win++;
		else lost++;
		if (win >= 21 || lost >= 21) {
			if (abs(win - lost) >= 2) {
				printf("%d:%d\n", win, lost);
				win = 0, lost = 0;
			}
		}
	}
	printf("%d:%d\n", win, lost);
	return 0;
}
