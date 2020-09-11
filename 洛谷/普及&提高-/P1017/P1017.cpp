/*
*	Problem: P1017
*	Author: Insouciant21
*	Time: 2020/8/26 14:51:55
*/

#include <bits/stdc++.h>

using namespace std;

int n;
int R;

int main() {
	string num = "0123456789ABCDEFGHIJK";
	scanf("%d %d", &n, &R);
	printf("%d=", n);
	stringstream x;
	while (n) {
		int m = n % R;
		n /= R;
		if (m < 0) {
			m -= R;
			n++;
		}
		x << num[m];
	}
	string ans = x.str();
	reverse(ans.begin(), ans.end());
	printf("%s(base%d)", ans.c_str(), R);
	return 0;
}
