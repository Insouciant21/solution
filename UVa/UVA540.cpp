#include <bits/stdc++.h>

using namespace std;

int main() {
    int kase = 0;
    while (true) {
        int t;
        kase++;
        cin >> t;
        if (t == 0)
            break;

        cout << "Scenario #" << kase << endl;
        map<int, int> table;
        for (int k = 0, n; k < t; k++) {
            cin >> n;
            for (int i = 0, x; i < n; i++) {
                cin >> x;
                table[x] = k;
            }
        }
        queue<int> q, qt[1001];
        while (true) {
            string command;
            cin >> command;
            if (command[0] == 'S')
                break;
            if (command[0] == 'D') {
                cout << qt[q.front()].front() << endl;
                qt[q.front()].pop();
                if (qt[q.front()].empty())
                    q.pop();
            }
            if (command[0] == 'E') {
                int id;
                cin >> id;
                qt[table[id]].push(id);
                if (qt[table[id]].size() == 1)
                    q.push(table[id]);
            }
        }
        cout << endl;
    }
    return 0;
}
