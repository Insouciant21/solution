/*
 *	Problem: P1143
 *	Author: Insouciant21
 *	Time: 2020/8/25 12:23:12
 */

#include <bits/stdc++.h>

using namespace std;

int base, base_n;

int toIntValue(char t) {
    switch (t) {
        case 'A':
            return 10;
        case 'B':
            return 11;
        case 'C':
            return 12;
        case 'D':
            return 13;
        case 'E':
            return 14;
        case 'F':
            return 15;
    }
}

void toDex(string &s) {
    bool nega = false;
    string t = s;
    if (s[0] != '-')
        reverse(t.begin(), t.end());
    else {
        nega = true;
        t.erase(t.begin());
        reverse(t.begin(), t.end());
    }
    int dexNum = 0;
    for (int i = 0; i < t.length(); i++) {
        if (t[i] >= '0' && t[i] <= '9') {
            dexNum += (t[i] - '0') * pow(base, i);
        } else if (t[i] >= 'A' && t[i] <= 'Z') {
            dexNum += toIntValue(t[i]) * pow(base, i);
        }
    }
    if (nega)
        dexNum = -dexNum;
    s = to_string(dexNum);
}

string modToString(int x) {
    if (base_n < 11)
        return to_string(x);
    else {
        if (x < 10)
            return to_string(x);
        else {
            switch (x) {
                case 10:
                    return "A";
                case 11:
                    return "B";
                case 12:
                    return "C";
                case 13:
                    return "D";
                case 14:
                    return "E";
                case 15:
                    return "F";
            }
        }
    }
}

void toBase(string &s) {
    string ans;
    int dexNum = stoi(s);
    if (dexNum == 0) {
        s = '0';
        return;
    }
    int mod = 0;
    while (dexNum != 0) {
        mod = dexNum % base_n;
        ans += modToString(mod);
        dexNum = (dexNum - mod) / base_n;
    }
    reverse(ans.begin(), ans.end());
    s = ans;
}

int main() {
    ios::sync_with_stdio(false);
    string num;
    cin >> base >> num >> base_n;
    toDex(num);
    toBase(num);
    cout << num << endl;
    return 0;
}
