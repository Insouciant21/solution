#include <bits/stdc++.h>

using namespace std;

struct Point {
    int x, y;
};

bool operator==(Point a, Point b) {
    return a.x == b.x && a.y == b.y;
}
struct Command {
    int mode;
    Point a, b;
    vector<int> oper;
};

vector<Command> commands;

int getMode(const string &k) {
    if (k == "EX")
        return 5;
    if (k == "DC")
        return 1;
    if (k == "DR")
        return 2;
    if (k == "IC")
        return 3;
    if (k == "IR")
        return 4;
}

void simulate(Point &k) {
    for (auto &command : commands) {
        switch (command.mode) {
            case 1: {
                int lower = 0;
                for (int i : command.oper) {
                    if (i < k.y)
                        lower++;
                    if (i == k.y) {
                        k.y = 100;
                        return;
                    }
                }
                k.y -= lower;
                break;
            }
            case 2: {
                int lower = 0;
                for (int i : command.oper) {
                    if (i < k.x)
                        lower++;
                    if (i == k.x) {
                        k.x = 100;
                        return;
                    }
                }
                k.x -= lower;
                break;
            }
            case 3: {
                int lower = 0;
                for (int i : command.oper)
                    if (i <= k.y)
                        lower++;
                k.y += lower;
                break;
            }
            case 4: {
                int lower = 0;
                for (int i : command.oper)
                    if (i <= k.x)
                        lower++;
                k.x += lower;
                break;
            }
            case 5:
                if (command.a == k) {
                    k.x = command.b.x;
                    k.y = command.b.y;
                }
                else if (command.b == k) {
                    k.x = command.a.x;
                    k.y = command.a.y;
                }
                break;
        }
    }
}

int main() {
    int r, c;
    int kase = 0;
    while (true) {
        cin >> r >> c;
        if (r == 0 || c == 0)
            break;
        int n;
        cin >> n;
        for (int i = 0; i < n; i++) {
            string m;
            cin >> m;
            Command t {};
            t.mode = getMode(m);
            if (m == "EX")
                cin >> t.a.x >> t.a.y >> t.b.x >> t.b.y;
            else {
                int A = 0;
                cin >> A;
                for (int j = 0; j < A; j++) {
                    int g;
                    cin >> g;
                    t.oper.push_back(g);
                }
            }
            commands.push_back(t);
        }
        int q;
        cin >> q;
        kase++;
        if (kase != 1)
            printf("\n");
        printf("Spreadsheet #%d\n", kase);
        while (q--) {
            Point u {};
            cin >> u.x >> u.y;
            int px = u.x, py = u.y;
            simulate(u);
            if (u.x != 100 && u.y != 100)
                printf("Cell data in (%d,%d) moved to (%d,%d)\n", px, py, u.x, u.y);
            else
                printf("Cell data in (%d,%d) GONE\n", px, py);
        }
        commands.clear();
    }
    return 0;
}
