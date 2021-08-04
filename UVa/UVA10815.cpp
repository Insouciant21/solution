#include <bits/stdc++.h>

using namespace std;

int main() {
    string s;
    set<string> k;
    while (cin >> s) {
        for (char &i : s) {
            if (isalpha(i))
                i = char(tolower(i));
            else
                i = ' ';
        }
        stringstream ss(s);
        while (ss >> s) k.insert(s);
    }
    for (auto &i : k) cout << i << endl;
    return 0;
}
