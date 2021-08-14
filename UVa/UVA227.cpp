#include <bits/stdc++.h>

using namespace std;

int main() {
    int kase = 0;
    while (true) {
        string grid[5];
        for (auto &i : grid) i = "";
        kase++;
        char ch = getchar();
        if (ch == '\n') ch = getchar();
        if (ch == 'Z') return 0;
        grid[0] += ch;
        for (auto &i : grid) {
            string t;
            getline(cin, t);
            i += t;
        }
        int x = 0, y = 0;
        bool find = false;
        for (int i = 0; i < 5; i++) {
            for (int j = 0; j < 5; j++) {
                if (grid[i][j] == ' ') {
                    x = i, y = j;
                    find = true;
                    break;
                }
            }
            if (find) break;
        }
        if (!find) {
            for (int i = 0; i < 5; i++) {
                if (grid[i].size() == 4) {
                    x = i, y = 4;
                    grid[i] += ' ';
                    break;
                }
            }
        }
        bool success = true;
        while (true) {
            char i = getchar();
            if (i == '\n') i = getchar();
            if (i == '0') break;
            switch (i) {
                case 'A':
                    if (x - 1 < 0) {
                        success = false;
                        break;
                    }
                    swap(grid[x][y], grid[x - 1][y]);
                    x--;
                    break;
                case 'B':
                    if (x + 1 > 4) {
                        success = false;
                        break;
                    }
                    swap(grid[x][y], grid[x + 1][y]);
                    x++;
                    break;
                case 'L':
                    if (y - 1 < 0) {
                        success = false;
                        break;
                    }
                    swap(grid[x][y], grid[x][y - 1]);
                    y--;
                    break;
                case 'R':
                    if (y + 1 > 4) {
                        success = false;
                        break;
                    }
                    swap(grid[x][y], grid[x][y + 1]);
                    y++;
                    break;
            }
        }
        if (kase != 1) printf("\n");
        printf("Puzzle #%d:\n", kase);
        if (!success) printf("This puzzle has no final configuration.\n");
        else {
            for (auto &i : grid) {
                for (int j = 0; j < 5; j++) printf((j == 0) ? "%c" : " %c", i[j]);
                printf("\n");
            }
        }
    }
}
