#include <bits/stdc++.h>

using namespace std;

int main() {
    string s;
    while (true) {
        list<char> p;
        getline(cin, s);
        int home = 0;
        for (char i : s) {
            if (i == '[') {
                home = 1;
                continue;
            }
            if (i == ']') {
                home = false;
                continue;
            }
            if (home) {
                p.insert(next(p.begin(), home++ - 1), i);
            }
            else p.push_back(i);
        }
        for (auto i : p) cout << i;
        if (!cin.eof()) cout << endl;
        else break;
    }
    return 0;
}
