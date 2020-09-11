#include <iostream>
#include <vector>

using namespace std;

int x, y, cnt = 0;
vector<int>leap;

int main()
{
    cin >> x >> y;
    for (int i = x; i <= y; i++) {
        if (i % 4 == 0) {
            if (i % 100 != 0 || i % 400 == 0) {
                leap.push_back(i);
                cnt++;
            }
        }
    }
    cout << cnt << endl;
    for (auto iter = leap.begin(); iter != leap.end(); iter++) {
        if (iter != leap.end() - 1)
            cout << *iter << " ";
        else cout << *iter << endl;
    }
}