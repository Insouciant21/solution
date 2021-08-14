#include <bits/stdc++.h>

using namespace std;

char text[201][201];
int n;

void dfs(int x, int y) {
    printf("%c(", text[x][y]);
    if (x + 1 < n && text[x + 1][y] == '|') {
        x += 2;
        int i = y;
        while (i - 1 >= 0 && text[x][i - 1] == '-') i--;
        for (; text[x][i] == '-' && text[x + 1][i] != '\0'; i++)
            if (!isspace(text[x + 1][i])) dfs(x + 1, i);
    }
    printf(")");
}

int main() {
    int T;
    fgets(text[0], 201, stdin);
    T = strtol(text[0], nullptr, 0);
    while (T--) {
        n = 0;
        while (true) {
            fgets(text[n], 201, stdin);
            if (text[n][0] == '#') break;
            else n++;
        }
        printf("(");
        if (n != 0) {
            for (int i = 0; i < strlen(text[0]); i++) {
                if (text[0][i] != ' ') {
                    dfs(0, i);
                    break;
                }
            }
        }
        printf(")\n");
        memset(text, 0, sizeof text);
    }
    return 0;
}
