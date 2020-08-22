#include <bits/stdc++.h>

using namespace std;

int main() {
	int a = 0, b = 0, c = 0;
	char t1, t2, t3, t4, t5;
	while (cin >> t1 >> t2 >> t3 >> t4 >> t5) {
		switch (t1)
		{
		case 'a':
		{
			if (t4 >= '0' && t4 <= '9') {
				a = t4 - '0';
			}
			else if (t4 == 'b') a = b;
			else if (t4 == 'c') a = c;
			break;
		}
		case 'b':
		{
			if (t4 >= '0' && t4 <= '9') {
				b = t4 - '0';
			}
			else if (t4 == 'a') b = a;
			else if (t4 == 'c') b = c;
			break;
		}
		case 'c':
		{
			if (t4 >= '0' && t4 <= '9') {
				c = t4 - '0';
			}
			else if (t4 == 'b') c = b;
			else if (t4 == 'a') c = a;
			break;
		}
		default:
			break;
		}
	}
	printf("%d %d %d", a, b, c);
	return 0;
}
