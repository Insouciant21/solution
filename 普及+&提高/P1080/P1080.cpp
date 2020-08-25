/*
*	Problem: P1080
*	Author: Insouciant21
*	Time: 2020/8/24 20:42:02
*/

#include <bits/stdc++.h>

using namespace std;

struct Node {
    __int128_t left;
    __int128_t right;
};

int main() {
    Node king;
    vector<Node>minister;
    ios::sync_with_stdio(false);
    int n;
    cin >> n;
    cin >> king.left >> king.right;
    Node t;
    for (int i = 0; i < n; i++) {
        cin >> t.left >> t.right;
        minister.push_back(t);
    }
    sort(minister.begin(), minister.end(), [](Node a, Node b) {return a.left * a.right < b.left *b.right; });
    minister.insert(minister.begin(), king);
    __int128_t gold = 1;
    for (int i = 0; i < n; i++) {
        gold *= minister[i].left;
    }
    gold /= minister.back().right;
    cout << gold << endl;
    return 0;
}
