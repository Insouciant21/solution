/* 
*  Problem: P1631
*  Author: Insouciant21
*  Time: 2020/9/20 11:36:12
*  Status: NULL
*/

#include <bits/stdc++.h>

using namespace std;

const int maxn = int(1e5) + 10;

int n;
int a[maxn], b[maxn];
priority_queue<int, vector<int>, less<int>>q;

int main() {
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
        scanf("%d", a + i);
    for (int i = 1; i <= n; i++)
        scanf("%d", b + i);
    for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			int x = a[i] + b[j];
			if (q.size() < n)
				q.push(x);
			else {
                if (q.top() > x) {
                    q.pop();
                    q.push(x);
                }
                else break;
			}
		}
    }
    stack<int>p;
    while (n) {
        p.push(q.top());
        q.pop();
        n--;
    }
    while (!p.empty()) {
        printf("%d ", p.top());
        p.pop();
    }
    return 0;
}
