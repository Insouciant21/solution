/* 
*  Problem: P1440
*  Author: Insouciant21
*  Time: 2020/9/6 20:49:50
*  Status: Accepted
*/

#include <bits/stdc++.h>

#define maxn 2000001

using namespace std;

int q[maxn], a[maxn];

int main() {
	int n, k;
	scanf("%d%d", &n, &k);
	for (int i = 0; i < n; i++)
		scanf("%d", &a[i]);
	int head = 0, tail = 0;
	cout << 0 << endl;
	for (int i = 0; i < n - 1; i++) {
		while (head <= tail && q[head] <= i - k)
			head++;
		while (tail >= head && a[i] < a[q[tail]])
			tail--;
		q[++tail] = i;
		printf("%d\n", a[q[head]]);
	}
	return 0;
}
