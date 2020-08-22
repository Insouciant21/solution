#include <iostream>

using namespace std;

int main() {
	int count = 0;
	int N;
	cin >> N;
	int *queue = new int[N];
	for (int i = 0; i < N; i++)cin >> queue[i];
	for (int i = 0; i < N; i++) {
		for (int j = i; j < N; j++) {
			if (queue[i] > queue[j])count++;
		}
	}
	cout << count << endl;
}
