#include <bits/stdc++.h>

using namespace std;

char t[1000001];
map<long long, int> f;

int main() {
    int T;
    scanf("%d", &T);
    while (T--) {
        scanf("%s", &t);
        for (int i = 0, g = 0; i < strlen(t); i++) {
            if (t[i] == '[') g++;
            else if (t[i] == ']') g--;
            else if (t[i] == ',') continue;
            else {
                long long p;
                sscanf(t + i, "%lld", &p);
                f[p]++;
                while (isdigit(t[i + 1])) i++;
            }
        }
    }
    return 0;
}
