#include <iostream>
#include <vector>

using namespace std;

int X, Y, I;

int main() {
	cin >> X >> Y >> I;
	bool **size = new bool *[X];
	for (int i = 0; i < X; i++) { size[i] = new bool[Y]; }
	for (int i = 0; i < X; i++)
		for (int j = 0; j < Y; j++) size[i][j] = false;
	vector<int>Xll, Yll, Xur, Yur;
	int t_1, t_2, t_3, t_4;
	for (int i = 1; i <= I; i++) {
		cin >> t_1 >> t_2 >> t_3 >> t_4;
		Xll.push_back(t_1);
		Yll.push_back(t_2);
		Xur.push_back(t_3);
		Yur.push_back(t_4);
	}
	for (int x = 0; x < I; x++) {
		for (int i = Xll[x]-1; i <= Xur[x]-1; i++) {
			for (int j = Yll[x]-1; j <= Yur[x]-1; j++) {
				size[i][j] = true;
			}
		}
	}
	int count = 0;
	for (int i = 0; i < X; i++)
			for (int j = 0; j < Y; j++) if (size[i][j])count++;
	cout << count << endl;
}
