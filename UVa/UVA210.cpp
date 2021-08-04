#include <bits/stdc++.h>

using namespace std;

struct Program {
    int id = 0;
    int execution = 0;
    vector<string> commands;
};

int main() {
    int kase;
    cin >> kase;
    for (int ka = 0; ka < kase; ka++) {
        if (ka)
            cout << endl;
        map<char, int> var;
        int n, t1, t2, t3, t4, t5, Q;
        cin >> n >> t1 >> t2 >> t3 >> t4 >> t5 >> Q;
        deque<int> ready;
        queue<int> blocked;
        vector<Program> programs;
        getchar();
        for (int i = 1; i <= n; i++) {
            Program t;
            t.id = i;
            while (true) {
                string s;
                getline(cin, s);
                if (s == "end")
                    break;
                t.commands.push_back(s);
            }
            programs.push_back(t);
            ready.push_back(i);
        }
        for (char i = 'a'; i <= 'z'; i++) var[i] = 0;
        int lock = -1;
        while (!ready.empty()) {
            int q = Q;
            Program &now = programs[ready.front() - 1];
            ready.pop_front();
            while (now.execution != now.commands.size()) {
                stringstream command(now.commands[now.execution++]);
                string c;
                command >> c;
                if (c == "print") {
                    string var_name;
                    command >> var_name;
                    cout << now.id << ": " << var[var_name[0]] << endl;
                    q -= t2;
                }
                else if (c == "lock") {
                    if (lock != -1) {
                        blocked.push(now.id);
                        now.execution--;
                        break;
                    }
                    lock = now.id;
                    q -= t3;
                }
                else if (c == "unlock") {
                    if (!blocked.empty()) {
                        ready.push_front(blocked.front());
                        blocked.pop();
                    }
                    lock = -1;
                    q -= t4;
                }
                else {
                    string cmd;
                    command >> cmd;
                    int var_value;
                    command >> var_value;
                    var[c[0]] = var_value;
                    q -= t1;
                }
                if (q <= 0) {
                    ready.push_back(now.id);
                    break;
                }
            }
        }
    }
    return 0;
}
