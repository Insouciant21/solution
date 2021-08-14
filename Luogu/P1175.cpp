/*
 *  Problem: P1175
 *  Author: Insouciant21
 *  Time: 2020/9/13 21:53:45
 *  Status: Accepted
 */

#include <bits/stdc++.h>

using namespace std;

constexpr int inf = 0x3f3f3f;

stack<char> oper;
stack<char> last;
stack<int> num;

map<char, int> priority;

int main() {
    string back;
    string m;
    cin >> m;
    priority['('] = inf;
    priority['+'] = priority['-'] = 0;
    priority['*'] = priority['/'] = 1;
    priority['^'] = 2;
    for (unsigned i = 0; i < m.length(); i++) {
        if (m[i] == ')') {
            while (oper.top() != '(') {
                back += oper.top();
                oper.pop();
            }
            oper.pop();
        }
        else if (m[i] == '(') {
            oper.push(m[i]);
        }
        else if (m[i] == '+' || m[i] == '-' || m[i] == '*' || m[i] == '/' || m[i] == '^') {
            while (oper.size() && oper.top() != '(' && priority[oper.top()] >= priority[m[i]]) {
                back += oper.top();
                oper.pop();
            }
            oper.push(m[i]);
        }
        else if (m[i] >= '0' && m[i] <= '9')
            back += m[i];
        else
            oper.push(m[i]);
    }
    while (oper.size()) {
        back += oper.top();
        oper.pop();
    }
    for (unsigned i = 0; i < back.length(); i++) {
        cout << back[i] << " ";
    }
    cout << endl;
    reverse(back.begin(), back.end());
    for (unsigned i = 0; i < back.length(); i++)
        last.push(back[i]);
    while (last.size()) {
        char p = last.top();
        last.pop();
        if (p >= '0' && p <= '9')
            num.push(p - '0');
        else {
            int a = num.top();
            num.pop();
            int b = num.top();
            num.pop();
            if (p == '+') num.push(a + b);
            if (p == '-') num.push(b - a);
            if (p == '*') num.push(a * b);
            if (p == '/') num.push(b / a);
            if (p == '^') num.push(pow(b, a));
            stack<char> m(last);
            stack<int> c;
            stack<int> l(num);
            while (l.size()) {
                c.push(l.top());
                l.pop();
            }
            while (c.size()) {
                cout << c.top() << " ";
                c.pop();
            }
            while (m.size()) {
                cout << m.top() << " ";
                m.pop();
            }
            cout << endl;
        }
    }
    return 0;
}
