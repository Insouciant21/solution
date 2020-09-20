/*
 *	Problem: P1067
 *	Author: Insouciant21
 *	Time: 2020/8/23 13:05:46
 */

#include <bits/stdc++.h>

using namespace std;

int main() {
    int n;
    cin >> n;
    int coef;
    string ans;
    stringstream ss;
    for (int i = n; i >= 0; i--) {
        cin >> coef;
        if (i == 0) {
            if (coef != 0) {
                if (coef > 0)
                    ss << '+' << coef;
                else
                    ss << '-' << -coef;
            }
        } else if (i == 1) {
            if (coef != 0) {
                if (coef > 0) {
                    if (coef == 1)
                        ss << "+x";
                    else
                        ss << '+' << coef << "x";
                } else {
                    if (coef == -1)
                        ss << "-x";
                    else
                        ss << '-' << -coef << "x";
                }
            }
        } else if (coef > 0) {
            if (coef == 1)
                ss << '+' << "x^" << i;
            else
                ss << '+' << coef << "x^" << i;
        } else if (coef < 0) {
            if (coef == -1)
                ss << '-' << "x^" << i;
            else
                ss << '-' << -coef << "x^" << i;
        }
    }
    ss >> ans;
    if (ans[0] == '+')
        ans.erase(ans.begin());
    cout << ans << endl;
    return 0;
}
