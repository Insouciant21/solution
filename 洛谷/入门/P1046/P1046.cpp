#include <iostream>

using namespace std;

int main() {
    int h[10], tall, cnt = 0;
    for (int i = 0; i < 10; i++) cin >> h[i];
    cin >> tall;
    for (int i = 0; i < 10; i++) {
        if (tall + 30 >= h[i])
            cnt++;
    }
    cout << cnt << endl;
    return 0;
}
