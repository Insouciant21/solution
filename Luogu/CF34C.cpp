/*
  Problem: CF34C
  Time: 2020/10/02 09:28:42
  Author: Insouciant21
  Status: Accepted
*/

#include <bits/stdc++.h>

using namespace std;

vector<int> num;
string ans;

int main() {
    string x;
    while (getline(cin, x, ',')) num.push_back(stoi(x));
    sort(num.begin(), num.end());
    num.erase(unique(num.begin(), num.end()), num.end());
    int l = num.front();
    int r = num.front();
    num.push_back(0x3f3f3f);
    for (auto i = num.begin(); i != num.end() - 1; i++) {
        if (*i == *(i + 1) - 1) {
            r++;
        }
        else {
            if (l == r) {
                stringstream ss;
                ss << l << ',';
                ans += ss.str();
                ss.clear();
            }
            else {
                stringstream ss;
                ss << l << '-' << r << ',';
                ans += ss.str();
                ss.clear();
            }
            l = r = *(i + 1);
        }
    }
    ans.pop_back();
    cout << ans << endl;
    return 0;
}