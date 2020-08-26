/*
*	Problem: P1575
*	Author: Insouciant21
*	Time: 2020/8/26 17:11:03
*	Unaccepted 80
*/

#include <bits/stdc++.h>

using namespace std;

inline string opposite(string x) {
    if (x == "true") return "false";
    else return "true";
}

inline string both(string x,string y) {
    if (x == "true" && y == "true") return "true";
    return "false";
}

inline string either(string x, string y) {
    if (x == "false" && y == "false") return "false";
    return "true";
}

inline bool validate(string x, string y) {
    if ((x == "true" || x == "false") && (y == "true" || y == "false")) return true;
    return false;
}

int main() {
    stringstream ss;
    string t;
    getline(cin, t);
    ss << t;
    vector<string>x;
    while (ss >> t) {
        x.push_back(t);
    }
    for (auto iter=x.begin(); iter!=x.end(); iter++) {
        if (*iter == "not") {
            if (iter != x.end() - 1) {
                if (*(iter + 1) == "true" || *(iter + 1) == "false") {
                    *(iter + 1) = opposite(*(iter + 1));
                    iter = x.erase(iter);
                }
                else {
                    cout << "error" << endl;
                    return 0;
                }
            }
            else {
                cout << "error" << endl;
                return 0;
            }
        }
    }
    for (auto iter = x.begin(); iter != x.end(); iter++) {
        if (*iter == "and") {
            if (iter == x.begin() || iter == x.end() - 1) {
                cout << "error" << endl;
                return 0;
            }
            else {
                if (validate(*(iter - 1), *(iter + 1))) {
                    t = either(*(iter - 1), *(iter + 1));
                    iter = x.erase(iter - 1);
                    x.erase(iter + 1);
                    *iter = t;
                }
                else {
                    cout << "error" << endl;
                    return 0;
                }
            }
        }
    }
    for (auto iter = x.begin(); iter != x.end(); iter++) {
        if (*iter == "or") {
            if (iter == x.begin() || iter == x.end() - 1) {
                cout << "error" << endl;
                return 0;
            }
            else {
                if (validate(*(iter - 1), *(iter + 1))) {
                    t = either(*(iter - 1), *(iter + 1));
                    iter = x.erase(iter - 1);
                    x.erase(iter + 1);
                    *iter = t;
                }
                else {
                    cout << "error" << endl;
                    return 0;
                }
            }
        }
    }
    if (x.size() != 1)
        cout << "error" << endl;
    else
        cout << x[0] << endl;
    return 0;
}
