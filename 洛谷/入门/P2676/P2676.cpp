#include <iostream>
#include <queue>
#include <algorithm>
#include <functional>

using namespace std;

int N, B, S = 0;

priority_queue<int, vector<int>, less<int>> H_i;

int main() {
    cin >> N >> B;
    for (int i = 0, t; i < N; i++) {
        cin >> t;
        S += t;
        H_i.push(t);
    }
    int result = 0, height = 0;
    while (height < B) {
        height += H_i.top();
        H_i.pop();
        result++;
    }
    cout << result << endl;
    return 0;
}
