#include <bits/stdc++.h>

using namespace std;

int a, b, c, d;

int gcd(int a, int b) {
	if (b == 0)return a;
	else return gcd(b, a % b);
}

int main() {
	scanf_s("%d/%d", &a, &b);
	scanf_s("%d/%d", &c, &d);
	int x, y;
	x = a * c;
	y = b * d;
	int g = gcd(x, y);
	x /= g;
	y /= g;
	printf("%d %d", x, y);
	return 0;
}
