/*
*	Problem: P1124
*	Author: Insouciant21
*	Time: 2020/8/26 18:40:35
*	It's not finished yet!
*/

#include <bits/stdc++.h>

using namespace std;

int main() {
	string S, id;
	int t;
	cin >> S >> t;
	for (size_t i = 0; i < S.length(); i++) id += to_string(i);
	make(StrNode(S, id));
	return 0;
}
