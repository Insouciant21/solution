#include <bits/stdc++.h>

using namespace std;

int n;
bool tmp;
vector<bool>checked;

int main() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> tmp;
        checked.push_back(tmp);
    }
    int continued = 0;
    int breaked = 0;
    int active = 0;
    for (int i = 0; i < n; i++) {
        if (checked[i]) {
            breaked = 0;
            while (checked[i])
            {
                continued++;
                if (continued < 3)active++;
                if (continued >= 3 && continued < 7)active += 2;
                if (continued >= 7 && continued < 30)active += 3;
                if (continued >= 30 && continued < 120)active += 4;
                if (continued >= 120 && continued < 365)active += 5;
                if (continued >= 365)active += 6;
                i++;
                if (i >= checked.size())break;
            }
            i--;
        }
        else {
            while (!checked[i])
            {
                breaked++;
                i++;
                if (i >= checked.size())break;
            }
            i--;
            continued -= pow(2, breaked - 1);
            breaked = 0;
        }
    }
    cout << active << endl;
    cout<<setprecision()
    return 0;
}
