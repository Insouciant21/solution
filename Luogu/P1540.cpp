#include <bits/stdc++.h>
using namespace std;
int q[1010];
int main() {
    memset(q, 0, sizeof q);
    int m, n;
    scanf("%d %d", &m, &n);
    int ans = 0;
    int head = 0, tail = 0;
    for (int i = 0; i < n; i++) {
        int c;
        scanf("%d", &c);
        bool ext = true;
        for (int j = head; j < tail; j++) {
            if (q[j] == c) {
                ext = false;
                break;
            }
        }
        ans += ext;
        if (ext) {
            q[tail++] = c;
            while (tail - head > m)
                head++;
        }
        // for(int k=head;k<tail;k++) printf("%d ",q[k]);
        // printf("\n");
    }
    printf("%d\n", ans);
}