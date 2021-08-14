#include <bits/stdc++.h>

using namespace std;

map<string, int> ID;
vector<string> Name;
map<string, int> installed;
map<string, vector<string>> g;
list<string> installedList;

bool isNeeded(const string &id) {
    for (const auto &i : installedList)
        for (const auto &j : g[i])
            if (j == id) return true;
    return false;
}

void install(const string &id, bool top) {
    for (auto &i : g[id])
        if (!installed[i]) install(i, false);
    cout << "   Installing " << id << endl;
    installed[id] = (top) ? 1 : 2;
    installedList.push_back(id);
}

void remove(const string &id) {
    cout << "   Removing " << id << endl;
    installed[id] = 0;
    installedList.erase(find(installedList.begin(), installedList.end(), id));
    for (auto &i : g[id])
        if (!isNeeded(i) && installed[i] == 2) remove(i);
}

int main() {
    while (true) {
        string c;
        getline(cin, c);
        stringstream ss(c);
        string command;
        ss >> command;
        cout << c << endl;
        if (command[0] == 'E') break;
        if (command[0] == 'D') {
            string t, f;
            ss >> t;
            while (ss >> f) g[t].push_back(f);
        }
        if (command[0] == 'I') {
            string item;
            ss >> item;
            if (installed[item]) {
                cout << "   " << item << " is already installed." << endl;
                continue;
            }
            install(item, true);
        }
        if (command[0] == 'L') {
            for (const auto &i : installedList) cout << "   " << i << endl;
        }
        if (command[0] == 'R') {
            string item;
            ss >> item;
            if (!installed[item]) {
                cout << "   " << item << " is not installed." << endl;
                continue;
            }
            if (isNeeded(item)) {
                cout << "   " << item << " is still needed." << endl;
                continue;
            }
            remove(item);
        }
    }
    return 0;
}
