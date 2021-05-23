/*
 *	Problem: P1098
 *	Author: Insouciant21
 *	Time: 2020/8/23 13:28:25
 */

#include <bits/stdc++.h>

using namespace std;

bool validate(char x, char y) {
    if (('0' <= x && x <= '9' && '0' <= y && y <= '9') || ('a' <= x && x <= 'z' && 'a' <= y && y <= 'z') || ('A' <= x && x <= 'Z' && 'A' <= y && y <= 'Z'))
        return true;
    return false;
}

int type(char x) {
    if (x >= 'a' && x <= 'z')
        return 0;
    if (x >= 'A' && x <= 'Z')
        return 1;
    if (x >= '0' && x <= '9')
        return 2;
    return 0;
}

string generate(string x, int a, int b, int c) {
    string ans;
    char filled;
    for (char i = x.front() + 1; i < x.back(); i++) {
        switch (type(i)) {
            case 0:
                if (a == 1)
                    filled = i;
                else if (a == 2)
                    filled = toupper(i);
                else if (a == 3)
                    filled = '*';
                break;
            case 1:
                if (a == 1)
                    filled = tolower(i);
                else if (a == 2)
                    filled = i;
                else if (a == 3)
                    filled = '*';
                break;
            case 2:
                if (a != 3)
                    filled = i;
                else
                    filled = '*';
                break;
            default:
                filled = i;
                break;
        }
        for (int j = 1; j <= b; j++) {
            ans += filled;
        }
    }
    if (c == 2)
        reverse(ans.begin(), ans.end());
    stringstream ss;
    ss << x.front() << ans << x.back();
    ss >> ans;
    return ans;
}

int main() {
    int p1, p2, p3;
    cin >> p1 >> p2 >> p3;
    string pen;
    cin >> pen;
    size_t pos = 0;
    string replace, origin;
    stringstream ss;
    size_t f = pen.find_first_not_of('-'), b = pen.find_last_not_of('-');
    string fr = pen.substr(0, f);
    string bk = pen.substr(b + 1, pen.length());
    pen.erase(0, f);
    pen.erase(b + 1, pen.length());
    while (pen.find('-', pos) != string::npos) {
        pos = pen.find('-', pos);
        if (pos == 0 || pos == pen.length() - 1)
            continue;
        if (pen[pos - 1] < pen[pos + 1]) {
            if (validate(pen[pos - 1], pen[pos + 1])) {
                ss << pen[pos - 1] << pen[pos] << pen[pos + 1];
                ss >> origin;
                ss.clear();
                replace = generate(origin, p1, p2, p3);
                pen.erase(pos - 1, 3);
                pen.insert(pos - 1, replace);
            }
        }
        pos++;
    }
    cout << fr << pen << bk << endl;
    return 0;
}
