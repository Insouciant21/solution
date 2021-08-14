#include <bits/stdc++.h>

using namespace std;

string pre, in;

void post(int pos, int start, int end) {
    if (start > end) return;
    int k = int(find(in.begin() + start, in.begin() + end, pre[pos]) - in.begin());
    post(pos + 1, start, k - 1);
    post(pos + k + 1 - start, k + 1, end);
    cout << pre[pos];
}

int main() {
    while (cin >> pre >> in) {
        post(0, 0, int(in.size() - 1));
        cout << endl;
    }
    return 0;
}
