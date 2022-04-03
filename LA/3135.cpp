#include <bits/stdc++.h>
using namespace std;
struct Event {
    int time, period, pid;
};
struct cmp {
    bool operator()(Event a, Event b) { return (a.time != b.time) ? a.time > b.time : a.pid > b.pid; }
};
int main() {
    string s;
    priority_queue<Event, vector<Event>, cmp> pq;
    while (getline(cin, s) && s != "#") {
        Event e {};
        sscanf(s.c_str(), "Register %d %d", &e.pid, &e.period);
        e.time = e.period;
        pq.push(e);
    }
    int k;
    cin >> k;
    while (k--) {
        Event f = pq.top();
        pq.pop();
        cout << f.pid << endl;
        f.time += f.period;
        pq.push(f);
    }
}