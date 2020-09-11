/* 
*  Problem: P2947
*  Author: Insouciant21
*  Time: 2020/9/7 18:27:15
*  Status: Accepted
*/

#include <bits/stdc++.h>

#define maxn 100001

using namespace std;

int q[maxn], a[maxn], ans[maxn];
int n;

int main() {
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
        scanf("%d", &a[i]);
    int head = 0, tail = 0;
    for (int i = 1; i <= n; i++) {
        while (tail >= head && a[i] > a[q[tail]]) {
            ans[q[tail]] = i;
            tail--;
        }
        q[++tail] = i;
    }
    for (int i = 1; i <= n; i++)
        printf("%d\n", ans[i]);
    return 0;
}
