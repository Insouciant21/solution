#include <bits/stdc++.h>

using namespace std;

string in, post;

void pre(int pos, int start, int end) {
    if (start > end) return;
    int k = int(find(in.begin() + start, in.begin() + end, post[pos]) - in.begin());
    cout << post[pos];
    pre(pos - 1 - end + k, start, k - 1);
    pre(pos - 1, k + 1, end);
}

int main() {
    cin >> in >> post;
    pre(int(post.size() - 1), 0, int(in.size() - 1));
    cout << endl;
    return 0;
}
