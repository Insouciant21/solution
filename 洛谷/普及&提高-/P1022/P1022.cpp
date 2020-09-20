#include <bits/stdc++.h>

using namespace std;

void mover(string &s) {
    size_t pos = s.find('=');
    string left = s.substr(0, pos);
    string right = s.substr(pos + 1, s.length());
    for_each(right.begin(), right.end(), [](char &m) {
        if (m == '+')
            m = '-';
        else if (m == '-')
            m = '+';
    });
    if (right[0] == '+' || right[0] == '-') {
        left += right;
    } else {
        left += '-';
        left += right;
    }
    s = left;
}

int calc(string e) {
    vector<int> item;
    size_t pos = 0;
    int t;
    stringstream ss;
    for (size_t i = 1; i < e.length(); i++) {
        if (e[i] == '+' || e[i] == '-') {
            ss << e.substr(pos, i - pos);
            ss >> t;
            ss.clear();
            item.push_back(t);
            pos = i;
        }
    }
    ss << e.substr(pos, e.length());
    ss >> t;
    item.push_back(t);
    int sum = 0;
    for_each(item.begin(), item.end(), [&](int m) { sum += m; });
    return -sum;
}

int ukc(string e, char un) {
    stringstream ss;
    ss << "[\\+|-]?[\\d]*?" << un;
    string del;
    ss >> del;
    ss.clear();
    e = regex_replace(e, regex(del), "$0", regex_constants::format_no_copy);
    for (unsigned i = 0; i < e.length(); i++) {
        if (e[i] == 'a') {
            if (i == 0) {
                e.insert(0, "1");
            } else {
                if (e[i - 1] == '+' || e[i - 1] == '-')
                    e.insert(i, "1");
            }
        }
    }
    ss << un;
    ss >> del;
    e = regex_replace(e, regex(del), "");
    int ans = calc(e);
    return -ans;
}

int main() {
    string exp;
    getline(cin, exp);
    char unknown;
    for (unsigned i = 0; i < exp.length(); i++) {
        if (exp[i] >= 'a' && exp[i] <= 'z') {
            unknown = exp[i];
            break;
        }
    }
    exp = regex_replace(exp, regex("--"), "+");
    exp = regex_replace(exp, regex("\\+\\+"), "+");
    int sum = 0;
    stringstream ss;
    mover(exp);
    ss << "[\\+|-]?[\\d]*?" << unknown;
    string del;
    ss >> del;
    sum = ukc(exp, unknown);
    while (regex_search(exp, regex(del))) {
        exp = regex_replace(exp, regex(del), "");
    }
    int c = calc(exp);
    double ans = double(c) / sum;
    if (ans == 0.0)
        ans = -ans;
    cout << unknown << "=" << fixed << setprecision(3) << ans << endl;
}