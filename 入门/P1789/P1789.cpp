#include <iostream>
using namespace std;
bool square[101][101];
int n, m, k;
int *torch_x = new int[m + 1];
int *torch_y = new int[m + 1];
int *fluo_x = new int[k + 1];
int *fluo_y = new int[k + 1];
int c[] = { 0,1,2,1,0 };

bool approved(int x, int y) {
	if (x<1 || y<1 || x>n || y>n) {
		return false;
	}
	else return true;
}

int main() {
	int z = 0;
	cin >> n >> m >> k;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++)
			square[i][j] = false;
	}
	for (int i = 1; i <= m; i++)
		cin >> torch_x[i] >> torch_y[i];
	for (int i = 1; i <= k; i++)
		cin >> fluo_x[i] >> fluo_y[i];
	for (int i = 1; i <= m; i++) {
		square[torch_x[i]][torch_y[i]] = true;
		for (int x = torch_x[i] - 2; x <= torch_x[i] + 2; x++) {
			for (int y = torch_y[i] - c[z]; y <= torch_y[i] + c[z]; y++) {
				if (approved(x, y))
					square[x][y] = true;
			}
			z++;
		}
		z = 0;
	}
	for (int i = 1; i <= k; i++) {
		for (int x = fluo_x[i] - 2; x <= fluo_x[i] + 2; x++) {
			for (int y = fluo_y[i] - 2; y <= fluo_y[i] + 2; y++) {
				if (approved(x, y))
					square[x][y] = true;
			}
		}
	}
	int dark = 0;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (!square[i][j])dark++;
		}
	}
	cout << dark << endl;

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (square[i][j])cout << "#";
			else cout << ".";
		}
		cout << endl;
	}
	return 0;
}