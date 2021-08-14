#include <bits/stdc++.h>

using namespace std;

int n;

struct Point {
    int p, h;
    Point(int a, int b) : p(a), h(b) {};
};

vector<int> blocks[25];

Point find_block(int id) {
    for (int i = 0; i < n; i++)
        for (int j = 0; j < blocks[i].size(); j++)
            if (blocks[i][j] == id) return {i, j};
}

void restore(Point k) {
    while (blocks[k.p].size() > k.h + 1) {
        blocks[blocks[k.p].back()].push_back(blocks[k.p].back());
        blocks[k.p].pop_back();
    }
}

void move(Point a, int p) {
    for (int i = a.h; i < blocks[a.p].size(); i++) blocks[p].push_back(blocks[a.p][i]);
    blocks[a.p].resize(a.h);
}

void print() {
    for (int i = 0; i < n; i++) {
        cout << i << ':';
        for (int j : blocks[i]) cout << " " << j;
        cout << endl;
    }
}

int main() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        blocks[i].clear();
        blocks[i].push_back(i);
    }
    while (true) {
        string p1, p2;
        int k1, k2;
        cin >> p1;
        if (p1 == "quit") {
            print();
            break;
        }
        cin >> k1 >> p2 >> k2;
        Point a = find_block(k1);
        Point b = find_block(k2);
        if (a.p == b.p) continue;
        if (p2 == "onto") restore(b);
        if (p1 == "move") restore(a);
        move(a, b.p);
    }
    return 0;
}
