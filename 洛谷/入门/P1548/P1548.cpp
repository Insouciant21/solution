#include <bits/stdc++.h>

using namespace std;

int N, M;

int main() {
    cin >> N >> M;
	int sumz = 0;
	int sumc = 0;
	if (N > M) {
		for (int i = M - 1; i >= 0; i--) {
			sumz += (N - i) * (M - i);
		}
	}
	else {
		for (int i = N - 1; i >= 0; i--) {
			sumz += (N - i) * (M - i);
		}
	}
	sumc = N * M * (N + 1) * (M + 1) / 4 - sumz;
	printf("%d %d", sumz, sumc);
    return 0;
}
