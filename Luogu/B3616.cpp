#include <bits/stdc++.h>

using namespace std;

int main() {
#ifdef LOCALENV
    freopen("test.in", "r", stdin);
    freopen("test.out", "w", stdout);
#endif
    queue<int> a;
    int n;
    cin >> n;
    while (n--) {
        int opt;
        cin >> opt;
        switch (opt) {
            case 1:
                int x;
                cin >> x;
                a.push(x);
                break;
            case 2:
                if (a.empty()) cout << "ERR_CANNOT_POP\n";
                else a.pop();
                break;
            case 3:
                if (a.empty()) cout << "ERR_CANNOT_QUERY\n";
                else cout << a.front() << endl;
                break;
            case 4: cout << a.size() << endl; break;
        }
    }
    return 0;
}