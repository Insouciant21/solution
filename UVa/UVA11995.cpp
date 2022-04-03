#include <bits/stdc++.h>
using namespace std;
int main() {
    int n;
    while (scanf("%d", &n)) {
        bool a, b, c, d;
        a = b = c = d = true;
        queue<int> q;
        stack<int> s;
        priority_queue<int> p1;
        priority_queue<int, vector<int>, less<int>> p2;
        for (int i = 0; i < n; i++) {
            int x, y;
            scanf("%d %d", &x, &y);
            if (x == 1) {
                if (a) q.push(y);
                if (b) s.push(y);
                if (c) p1.push(y);
                if (d) p2.push(y);
            }
            if (x == 2) {
                if (a && q.front() != y || q.empty()) a = false;
                else if (a && !q.empty()) q.pop();
                if (b && s.top() != y || s.empty()) b = false;
                else if (b && !s.empty()) s.pop();
                if (c && p1.top() != y || p1.empty()) c = false;
                else if (c && !p1.empty()) p1.pop();
                if (d && p2.top() != y || p2.empty()) d = false;
                else if (d && !p2.empty()) p2.pop();
            }
        }
        int cnt = a + b + (c || d);
        if (cnt >= 2) printf("not sure\n");
        else if (cnt == 0) printf("impossible\n");
        else if (cnt == 1) {
            if (a) printf("queue\n");
            else if (b) printf("stack\n");
            else if (c || d) printf("priority queue\n");
        }
    }
}