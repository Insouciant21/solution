#include <bits/stdc++.h>

using namespace std;

double n;

int main() {
	scanf_s("%lf", &n);
	double l = 2;
	double run = 0.98 * l;
	int cnt = 1;
	while (l < n)
	{
		l += run;
		run = run * 0.98;
		cnt++;
	}
	cout << cnt << endl;
	return 0;
}
