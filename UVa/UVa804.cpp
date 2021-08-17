#include <bits/stdc++.h>

using namespace std;

struct Task {
    unordered_map<int, int> in;
    unordered_map<int, int> out;
};

vector<int> places;
vector<Task> transitions;
int NP, NT, NF;

bool verify(const Task &x);
int getTask();
int bfs();
void printToken();

int main() {
    int kase = 0;
    while (++kase) {
        cin >> NP;
        if (NP == 0) break;
        places.clear(), transitions.clear();
        places.resize(NP + 1);
        for (int i = 1; i <= NP; i++) cin >> places[i];
        cin >> NT;
        transitions.resize(NT);
        for (int i = 0; i < NT; i++) {
            int t;
            while (cin >> t) {
                if (t == 0) break;
                if (t < 0) transitions[i].in[-t]++;
                if (t > 0) transitions[i].out[t]++;
            }
        }
        cin >> NF;
        int f = bfs();
        printf("Case %d: ", kase);
        if (f == NF) printf("still live after %d transitions\n", NF);
        else printf("dead after %d transitions\n", f);
        printToken();
    }
    return 0;
}

bool verify(const Task &x) {
    return all_of(x.in.begin(), x.in.end(), [](pair<int, int> x) { return places[x.first] >= x.second; });
}

int getTask() {
    for (int i = 0; i < NT; i++)
        if (verify(transitions[i])) return i;
    return -1;
}

void add(const Task &x) {
    for (auto i : x.in) places[i.first] -= i.second;
    for (auto i : x.out) places[i.first] += i.second;
}

int bfs() {
    for (int i = 0; i < NF; i++) {
        int task = getTask();
        if (task == -1) return i;
        add(transitions[task]);
    }
    return NF;
}

void printToken() {
    printf("Places with tokens:");
    for (int i = 1; i <= NP; i++) {
        if (places[i] == 0) continue;
        printf(" %d (%d)", i, places[i]);
    }
    printf("\n\n");
}