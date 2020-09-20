#include <bits/stdc++.h>

using namespace std;

class operation {
public:
    string in;
    char oper;
    int a, b;
    void print() {
        stringstream ss;
        string ans;
        switch (oper) {
            case '+':
                ss << a << oper << b << "=" << a + b;
                break;
            case '-':
                ss << a << oper << b << "=" << a - b;
                break;
            case '*':
                ss << a << oper << b << "=" << a * b;
                break;
            default:
                break;
        }
        ss >> ans;
        cout << ans << endl;
        cout << ans.length() << endl;
    }
    void oper_con() {
        switch (oper) {
            case 'a':
                oper = '+';
                break;
            case 'b':
                oper = '-';
                break;
            case 'c':
                oper = '*';
                break;
            default:
                break;
        }
    }
};

void convert(vector<operation> &s) {
    stringstream ss;
    ss << s[0].in;
    ss >> s[0].oper;
    ss >> s[0].a >> s[0].b;
    s[0].oper_con();
    ss.clear();
    for (unsigned i = 1; i < s.size(); i++) {
        ss << s[i].in;
        if (s[i].in[0] >= '0' && s[i].in[0] <= '9') {
            ss >> s[i].a >> s[i].b;
            s[i].oper = s[i - 1].oper;
        } else {
            ss >> s[i].oper >> s[i].a >> s[i].b;
        }
        s[i].oper_con();
        ss.clear();
    }
}

int main() {
    vector<operation> calc;
    int n;
    cin >> n;
    cin.get();
    operation t;
    for (int i = 0; i < n; i++) {
        getline(cin, t.in);
        calc.push_back(t);
    }
    convert(calc);
    for (unsigned i = 0; i < calc.size(); i++) {
        calc[i].print();
    }
    return 0;
}
