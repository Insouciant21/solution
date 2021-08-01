#include <bits/stdc++.h>

using namespace std;

struct Matrix {
    int r = 0, c = 0;
    explicit Matrix(int a = 0, int b = 0) : r(a), c(b) {};
};

map<char, Matrix> matrix;

int main() {
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        char k;
        Matrix g {};
        cin >> k >> g.r >> g.c;
        matrix[k] = g;
    }
    string expr;
    while (cin >> expr) {
        long long ans = 0;
        stack<Matrix> s;
        bool successful = true;
        for (char &point : expr) {
            if (point == ')') {
                Matrix a, b;
                b = s.top(), s.pop();
                a = s.top(), s.pop();
                if (a.c != b.r) {
                    successful = false;
                    cout << "error" << endl;
                    break;
                }
                ans += a.r * a.c * b.c;
                s.push(Matrix(a.r, b.c));
            }
            if (isalpha(point))
                s.push(matrix[point]);
        }
        if (successful)
            cout << ans << endl;
    }
    return 0;
}
