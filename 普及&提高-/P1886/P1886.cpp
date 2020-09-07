/* 
*  Problem: P1886
*  Author: Insouciant21
*  Time: 2020/9/7 17:49:36
*  Status: Accepted
*/

#include <bits/stdc++.h>

#define maxn 1000001

using namespace std;

int q[maxn], a[maxn];
int n, k;

void getMin() {
	int head = 0, tail = 0;
	for (int i = 0; i < n; i++) {
		while (head <= tail && q[head] < i + 1 - k)
			head++;
		while (tail >= head && a[i] < a[q[tail]])
			tail--;
		q[++tail] = i;
		if (i >= k - 1)
			cout << a[q[head]] << " ";
	}
}

void getMax() {
	int head = 0, tail = 0;
	for (int i = 0; i < n; i++) {
		while (head <= tail && q[head] < i + 1 - k)
			head++;
		while (tail >= head && a[i] > a[q[tail]])
			tail--;
		q[++tail] = i;
		if (i >= k - 1)
			cout << a[q[head]] << " ";
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin >> n >> k;
	for (int i = 0; i < n; i++)
		cin >> a[i];
	getMin();
	cout << endl;
	getMax();
	return 0;
}
