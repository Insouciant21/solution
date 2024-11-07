#include <bits/stdc++.h>

using namespace std;

int main() {
    int n;
    cin >> n;
    vector<vector<double>> data;
    data.resize(n);
    for (int i = 0; i < n; i++) {
        data[i].resize(n + 1);
        for (int j = 0; j < n + 1; j++) cin >> data[i][j];
    }
    int nowRow = 0;
    for (int nowCol = 0; nowCol < n; nowCol++) {
        if (data[nowRow][nowCol] == 0) {
            bool swapable = false;
            for (int j = nowRow + 1; j < n; j++) {
                if (data[j][nowCol] != 0) {
                    swap(data[nowRow], data[j]);
                    swapable = true;
                    break;
                }
            }
            if (!swapable) continue;
        }
        double c = data[nowRow][nowCol];
        for (int j = 0; j <= n; j++) data[nowRow][j] /= c;
        for (int j = 0; j < n; j++) {
            if (j == nowRow) continue;
            c = data[j][nowCol];
            for (int k = 0; k < n + 1; k++) data[j][k] -= c * data[nowRow][k];
        }
        nowRow++;
    }
    if (nowRow < n) {
        bool flag = false;
        while (nowRow < n)
            if (data[nowRow++][n] != 0) flag = true;
        if (flag) printf("-1\n");
        else printf("0\n");
    }
    else
        for (int i = 0; i < n; i++) printf("x%d=%.2f\n", i + 1, data[i][n]);
    return 0;
}