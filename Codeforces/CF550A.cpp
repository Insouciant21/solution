#include <bits/stdc++.h>

using namespace std;

int main() {
    string in;
    cin >> in;
    int a = 0, b = 0, p = 0;
    if (in.length() > 3) {
        for (int i = 0; i < in.length() - 2; i++) {
            if ((in[i] == 'A' && in[i + 1] == 'B' && in[i + 2] == 'A') ||
                (in[i] == 'B' && in[i + 1] == 'A' && in[i + 2] == 'B')) {
                in[i] = in[i + 1] = in[i + 2] = '#';
                p++;
            }
        }
        for (int i = 0; i < in.length() - 1; i++)
            if (in[i] == 'A' && in[i + 1] == 'B') a++;
        for (int i = 0; i < in.length() - 1; i++)
            if (in[i] == 'B' && in[i + 1] == 'A') b++;
        if ((a && b) || (a && p) || (b && p) || (p >= 2)) puts("YES");
        else puts("NO");
    }
    else puts("NO");
    return 0;
}
