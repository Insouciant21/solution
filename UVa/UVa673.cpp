#include <bits/stdc++.h>

using namespace std;

int main() {
    int n;
    string t;
    getline(cin, t);
    sscanf(t.c_str(), "%d", &n);
    while (n--) {
        stack<char> s;
        getline(cin, t);
        bool legal = true;
        for (char &i : t) {
            if (i == '(' || i == '[') s.push(i);
            if (i == ')' || i == ']') {
                if (s.empty()) {
                    legal = false;
                    break;
                }
                if ((s.top() == '(' && i == ')') || (s.top() == '[' && i == ']')) s.pop();
                else {
                    legal = false;
                    break;
                }
            }
        }
        if (legal && s.empty()) cout << "Yes" << endl;
        else cout << "No" << endl;
    }
    return 0;
}
