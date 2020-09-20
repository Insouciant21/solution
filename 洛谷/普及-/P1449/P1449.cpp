/*
 *  Problem: P1449
 *  Author: Insouciant21
 *  Time: 2020/9/13 20:28:26
 *  Status: NULL
 */

#include <bits/stdc++.h>

using namespace std;

stack<string> p;
stack<string> l;
stack<int> num;

int main() {
    string m;
    char t = ' ';
    while (t != '@') {
        cin >> t;
        if (t == '.') {
            l.push(m);
            m.clear();
        } else if (t < '0' || t > '9') {
            m.clear();
            m += t;
            l.push(m);
            m.clear();
        } else
            m += t;
    }
    l.pop();
    while (l.size()) {
        p.push(l.top());
        l.pop();
    }
    while (p.size()) {
        string n = p.top();
        p.pop();
        if (n == "+" || n == "-" || n == "*" || n == "/") {
            int a, b;
            a = num.top();
            num.pop();
            b = num.top();
            num.pop();
            if (n == "+")
                num.push(a + b);
            else if (n == "-")
                num.push(b - a);
            else if (n == "*")
                num.push(a * b);
            else if (n == "/")
                num.push(b / a);
        } else
            num.push(stoi(n));
    }
    cout << num.top() << endl;
    return 0;
}
