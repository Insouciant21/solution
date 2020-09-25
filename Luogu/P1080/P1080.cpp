/*
 *	Problem: P1080
 *	Author: Insouciant21
 *	Time: 2020/8/24 20:42:02
 */

#include <bits/stdc++.h>

using namespace std;

struct Node {
    int left, right;
    bool operator<(const Node &x) const {
        return max(x.right, left * right) < max(right, x.left * x.right);
    }
};
/*
inline __int128 read() {
        __int128 x = 0, f = 1;
        char ch = getchar();
        while (ch < '0' || ch>'9') {
                if (ch == '-')
                        f = -1;
                ch = getchar();
        }
        while (ch >= '0' && ch <= '9') {
                x = x * 10 + ch - '0';
                ch = getchar();
        }
        return x * f;
}

inline void print(__int128 x) {
        if (x < 0) {
                putchar('-');
                x = -x;
        }
        if (x > 9)
                print(x / 10);
        putchar(x % 10 + '0');
}
*/

int main() {
    ios::sync_with_stdio(0);
    Node king;
    vector<Node> mi;
    int n;
    scanf("%d", &n);
    // king.left = read(), king.right = read();
    cin >> king.left >> king.right;
    Node t;
    for (int i = 0; i < n; i++) {
        cin >> t.left >> t.right;
        mi.push_back(t);
    }
    sort(mi.begin(), mi.end());
    mi.insert(mi.begin(), king);
    int gold = 1;

    cout << endl << endl << endl;
    for (int i = 0; i <= n; i++) {
        cout << mi[i].left << " " << mi[i].right << endl;
    }
    /*
    for (int i = 0; i < n; i++) {
            gold *= mi[i].left;
    }
    gold /= mi.back().right;
    cout << gold << endl;*/
    return 0;
}
