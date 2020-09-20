/*
 *	Problem: P1603
 *	Author: Insouciant21
 *	Time: 2020/8/22 21:07:18
 */

#include <bits/stdc++.h>

using namespace std;

string number =
    " one two three four five six seven eight nine ten eleven twelve thirteen fourteen fifteen sixteen "
    "seventeen eighteen nineteen twenty a both another first second third ";

int convert(string t) {
    if (t == "one")
        return 1;
    if (t == "two")
        return 4;
    if (t == "three" || t == "third")
        return 9;
    ;
    if (t == "ten")
        return 0;
    if (t == "twelve")
        return 44;
    if (t == "thirteen")
        return 69;
    if (t == "twenty")
        return 0;
    if (t == "four")
        return 16;
    if (t == "five")
        return 25;
    if (t == "fifteen")
        return 25;
    if (t == "first")
        return 1;
    if (t == "six")
        return 36;
    if (t == "seven")
        return 49;
    if (t == "sixteen")
        return 56;
    if (t == "seventeen")
        return 89;
    if (t == "second")
        return 4;
    if (t == "eight")
        return 64;
    if (t == "eleven")
        return 21;
    if (t == "eighteen")
        return 24;
    if (t == "nine")
        return 81;
    if (t == "nineteen")
        return 61;
    if (t == "a")
        return 1;
    if (t == "another")
        return 1;
    if (t == "both")
        return 4;
}

int main() {
    string s, t, x;
    getline(cin, s);
    vector<string> p;
    stringstream ss;
    ss << s;
    stringstream si;
    int cnt = 0;
    while (ss >> t) {
        if (number.find(" " + t + " ") != string::npos) {
            cout << t << endl;
            si << setw(2) << setfill('0') << convert(t);
            si >> x;
            si.clear();
            p.push_back(x);
            cnt++;
        }
    }
    ss.clear();
    if (cnt == 0) {
        cout << 0 << endl;
        return 0;
    }
    sort(p.begin(), p.end());
    for_each(p.begin(), p.end(), [&](string x) { ss << x; });
    long long ans = 0;
    ss >> ans;
    cout << ans;
    return 0;
}
