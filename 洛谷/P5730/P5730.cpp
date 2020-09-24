#include <bits/stdc++.h>

using namespace std;

int n;
string m;

int main() {
    cin >> n >> m;
    vector<vector<bool>> mon(3 * n + n - 1, vector<bool>(5));
    for (int i = 0; i < 3 * n + n - 1; i++) {
        for (int j = 0; j < 5; j++) mon[i][j] = 0;
    }
    int row = 0, col = 0;
    for (int i = 0; i < n; i++) {
        switch (m[i]) {
            case '0': {
                for (int i = 0; i < 5; i++) {
                    mon[row][i] = 1;
                    mon[row + 2][i] = 1;
                }
                mon[row + 1][0] = 1;
                mon[row + 1][4] = 1;
                row += 4;
                break;
            }
            case '1': {
                for (int i = 0; i < 5; i++) mon[row + 2][i] = 1;
                row += 4;
                break;
            }
            case '2': {
                for (int i = row; i < row + 3; i++) {
                    mon[i][0] = 1;
                    mon[i][2] = 1;
                    mon[i][4] = 1;
                }
                mon[row + 2][1] = 1;
                mon[row][3] = 1;
                row += 4;
                break;
            }
            case '3': {
                for (int i = row; i < row + 3; i++) {
                    mon[i][0] = 1;
                    mon[i][2] = 1;
                    mon[i][4] = 1;
                }
                mon[row + 2][1] = 1;
                mon[row + 2][3] = 1;
                row += 4;
                break;
            }
            case '4': {
                for (int i = 0; i < 5; i++) mon[row + 2][i] = 1;
                for (int i = 0; i < 3; i++) mon[row][i] = 1;
                mon[row + 1][2] = 1;
                row += 4;
                break;
            }
            case '5': {
                for (int i = row; i < row + 3; i++) {
                    mon[i][0] = 1;
                    mon[i][2] = 1;
                    mon[i][4] = 1;
                }
                mon[row + 2][3] = 1;
                mon[row][1] = 1;
                row += 4;
                break;
            }
            case '6': {
                for (int i = row; i < row + 3; i++) {
                    mon[i][0] = 1;
                    mon[i][2] = 1;
                    mon[i][4] = 1;
                }
                mon[row + 2][3] = 1;
                mon[row][1] = 1;
                mon[row][3] = 1;
                row += 4;
                break;
            }
            case '7': {
                for (int i = 0; i < 5; i++) mon[row + 2][i] = 1;
                mon[row][0] = 1;
                mon[row + 1][0] = 1;
                row += 4;
                break;
            }
            case '8': {
                for (int i = row; i < row + 3; i++) {
                    mon[i][0] = 1;
                    mon[i][2] = 1;
                    mon[i][4] = 1;
                }
                mon[row + 2][3] = 1;
                mon[row][1] = 1;
                mon[row][3] = 1;
                mon[row + 2][1] = 1;
                row += 4;
                break;
            }
            case '9': {
                for (int i = row; i < row + 3; i++) {
                    mon[i][0] = 1;
                    mon[i][2] = 1;
                    mon[i][4] = 1;
                }
                mon[row + 2][3] = 1;
                mon[row][1] = 1;
                mon[row + 2][1] = 1;
                row += 4;
                break;
            }
        }
    }
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 3 * n + n - 1; j++) {
            if (mon[j][i])
                cout << "X";
            else
                cout << ".";
        }
        cout << endl;
    }
    return 0;
}
