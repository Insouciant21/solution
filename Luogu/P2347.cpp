#include <bits/stdc++.h>
using namespace std;
int f[1001];
int w[] = {1, 2, 3, 5, 10, 20};
vector<int> c;
int main() {
    int s = 0;
    int ans = 0;
    for (int & i : w) {
        int k;
        scanf("%d", &k);
        s += i * k;
        for (int j = 0; j < k; j++)
            c.push_back(i);
    }
    f[0] = 1;
    for (int i : c)
        for (int j = s; j >= i; j--)
            f[j] += f[j - i];
    for (int i = 1; i <= s; i++)
        if (f[i]) ans++;
    printf("Total=%d\n", ans);
    return 0;
}