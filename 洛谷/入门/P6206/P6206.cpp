#include <iostream>

using namespace std;

int main()
{
    int N;
    cin >> N;
    int score = 0;
    while (N != 1) {
        if (N % 2 != 0)
            N = N * 3 + 1;
        else
            N /= 2;
        score++;
    }
    cout << score << endl;
    return 0;
}
