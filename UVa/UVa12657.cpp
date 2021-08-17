#include <bits/stdc++.h>

using namespace std;

struct Node {
    int id;
    Node *prev;
    Node *next;
};

Node *boxes[100001];

struct List {
    Node *head;
    Node *tail;
    bool reversed = false;
    List() {
        head = new Node;
        tail = new Node;
        head->prev = head;
        head->next = tail;
        tail->prev = head;
        tail->next = tail;
    }
    void push(int data) const {
        Node *g = new Node;
        g->id = data;
        g->next = tail;
        tail->prev->next = g;
        g->prev = tail->prev;
        tail->prev = g;
        boxes[data] = g;
    }
    static void move(int x, int y, int mode) {
        Node *px = boxes[x], *py = boxes[y];
        if (mode == 1) {
            if (px->next == py) return;
            px->prev->next = px->next;
            px->next->prev = px->prev;
            py->prev->next = px;
            px->prev = py->prev;
            py->prev = px;
            px->next = py;
        }
        if (mode == 2) {
            if (py->next == px) return;
            px->prev->next = px->next;
            px->next->prev = px->prev;
            py->next->prev = px;
            px->next = py->next;
            px->prev = py;
            py->next = px;
        }
        if (mode == 3) {
            int k = px->id;
            px->id = py->id;
            py->id = k;
            swap(boxes[x], boxes[y]);
        }
    }
};

int main() {
    int kase = 0;
    int n, m;
    while (cin >> n >> m) {
        List g;
        for (int i = 1; i <= n; i++) g.push(i);
        for (int i = 0; i < m; i++) {
            int oper;
            cin >> oper;
            if (oper != 4) {
                int x, y;
                cin >> x >> y;
                if (g.reversed && (oper == 1 || oper == 2)) oper = (oper == 1) ? 2 : 1;
                List::move(x, y, oper);
            }
            else g.reversed = !g.reversed;
        }
        int pos = 0;
        Node *p = g.head;
        long long ans = 0;
        while (true) {
            pos++;
            p = p->next;
            if (p == g.tail) break;
            if ((pos % 2 == 1 && (!g.reversed || n % 2 == 1)) || (pos % 2 == 0 && g.reversed && n % 2 == 0))
                ans += p->id;
        }
        cout << "Case " << ++kase << ": " << ans << endl;
    }
    return 0;
}
