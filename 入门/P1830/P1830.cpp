#include <iostream>

using namespace std;


int N, M, X, Y;

int main() {
	cin >> N >> M >> X >> Y;
	bool **size = new bool *[N];
	for (int i = 0; i < N; i++) { size[i] = new bool[M]; }
	for (int i = 0; i < N; i++)
		for (int j = 0; j < M; j++) size[i][j] = false;
	int *x1 = new int[X];
	int *y1 = new int[X];
	int *x2 = new int[X];
	int *y2 = new int[X];
	int *crux_x = new int[Y];
	int *crux_y = new int[Y];
	bool *boom = new bool[Y];
	int *times = new int[Y];
	int *count = new int[Y];
	for (int i = 0; i < X; i++)cin >> x1[i] >> y1[i] >> x2[i] >> y2[i];
	for (int i = 0; i < Y; i++) { cin >> crux_x[i] >> crux_y[i]; count[i] = 0; boom[i] = false; }
	for (int x = 0; x < X; x++) {
		for (int i = x1[x]-1; i < x2[x]; i++) {
			for (int j = y1[x]-1; j < y2[x]; j++) {
				size[i][j] = true;
				for (int m = 0; m < Y; m++) {
					if (crux_x[m] == i+1 && crux_y[m] == j+1) {
						count[m]++;
						boom[m] = true;
						times[m] = x + 1;
					}
				}
			}
		}
	}
	for (int i = 0; i < Y; i++) {
		if (boom[i]) {
			cout << "Y " << count[i] << " " << times[i] << endl;
		}
		else cout << "N\n";
	}
}
