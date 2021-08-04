#include <bits/stdc++.h>

using namespace std;

char board[9][9];

int dx[] = {0, 0, 1, -1, 1, -1, 1, -1};
int dy[] = {1, -1, 0, 0, 1, -1, -1, 1};

char getOpposite(char k) {
    if (k == 'B')
        return 'W';
    if (k == 'W')
        return 'B';
    return '-';
}

bool legal(int x, int y, char next) {
    int px = x, py = y;
    for (int k = 0; k < 8; k++) {
        x = px, y = py;
        if (x + dx[k] > 7 || x + dx[k] < 0 || y + dy[k] > 7 || y + dy[k] < 0)
            continue;
        x += dx[k], y += dy[k];
        if (board[x][y] != getOpposite(next))
            continue;
        while (true) {
            x += dx[k], y += dy[k];
            if (x > 7 || x < 0 || y > 7 || y < 0)
                break;
            if (board[x][y] == next)
                return true;
            if (board[x][y] != getOpposite(next))
                break;
        }
    }
    return false;
}

void query(char next) {
    int cnt = 0;
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            if (board[i][j] != '-')
                continue;
            if (legal(i, j, next)) {
                cnt++;
                if (cnt > 1)
                    printf(" ");
                printf("(%d,%d)", i + 1, j + 1);
            }
        }
    }
    if (cnt == 0)
        printf("No legal move.");
    printf("\n");
}

void insert(char &next) {
    char tx, ty;
    cin >> tx >> ty;
    int x = tx - '0' - 1, y = ty - '0' - 1;
    const int px = x, py = y;
    if (!legal(x, y, next))
        next = getOpposite(next);
    board[x][y] = next;
    for (int k = 0; k < 8; k++) {
        x = px, y = py;
        int kx = px, ky = py;
        if (x + dx[k] > 7 || x + dx[k] < 0 || y + dy[k] > 7 || y + dy[k] < 0)
            continue;
        x += dx[k], y += dy[k];
        if (board[x][y] != getOpposite(next))
            continue;
        bool find = false;
        while (true) {
            x += dx[k], y += dy[k];
            if (x > 7 || x < 0 || y > 7 || y < 0)
                break;
            if (board[x][y] == '-')
                break;
            if (board[x][y] == next) {
                find = true;
                break;
            }
        }
        while (find) {
            board[kx][ky] = next;
            kx += dx[k], ky += dy[k];
            if (kx > 7 || kx < 0 || ky > 7 || ky < 0)
                break;
            if (kx == x && ky == y)
                break;
        }
    }
    int b = 0, w = 0;
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            if (board[i][j] == 'B')
                b++;
            if (board[i][j] == 'W')
                w++;
        }
    }
    printf("Black - %2d White - %2d\n", b, w);
}

int main() {
    int n;
    cin >> n;
    int kase = 0;
    while (n--) {
        kase++;
        if (kase != 1)
            cout << endl;
        for (int i = 0; i < 8; i++)
            cin >> board[i];
        char next;
        cin >> next;
        while (true) {
            char oper;
            cin >> oper;
            if (oper == 'Q') {
                for (int i = 0; i < 8; i++) {
                    for (int j = 0; j < 8; j++)
                        cout << board[i][j];
                    cout << endl;
                }
                break;
            }
            if (oper == 'L')
                query(next);
            if (oper == 'M') {
                insert(next);
                next = getOpposite(next);
            }
        }
    }
    return 0;
}
