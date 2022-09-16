#include <bits/stdc++.h>

using namespace std;

int main() {
    set<int> k;
    int T;
    cin >> T;
    while (T--) {
        int opt;
        int len;
        cin >> opt >> len;
        if (opt == 1) {
            auto m = k.size();
            k.insert(len);
            if (k.size() == m) cout << "Already Exist" << endl;
        }
        if (opt == 2) {
            if (k.empty()) cout << "Empty" << endl;
            else if (k.find(len) != k.end()) {
                cout << len << endl;
                k.erase(len);
            }
            else {
                auto it = k.lower_bound(len);
                auto m = it;
                m--;
                if (it == k.end()) {
                    auto a = max_element(k.begin(), k.end());
                    cout << *a << endl;
                    k.erase(a);
                }
                else if (it == k.begin()) {
                    cout << *it << endl;
                    k.erase(it);
                }
                else if (abs(*it - len) < abs(*(m)-len)) {
                    cout << *it << endl;
                    k.erase(it);
                }
                else cout << *m << endl, k.erase(m);
            }
        }
    }
}