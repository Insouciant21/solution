/*
*	Problem: P1068
*	Author: Insouciant21
*	Time: 2020/8/25 10:39:19
*/

#include <bits/stdc++.h>

using namespace std;

struct Node {
	int id;
	int score;
};

bool cmp(Node a, Node b) {
	if (a.score == b.score) return a.id < b.id;
	else return a.score > b.score;
}

void print(Node s) {
	cout << s.id << " " << s.score << endl;
}

int main() {
	ios::sync_with_stdio(false);
	int n, m;
	cin >> n >> m;
	Node tmp;
	vector<Node>member;
	for (int i = 0; i < n; i++) {
		cin >> tmp.id >> tmp.score;
		member.push_back(tmp);
	}
	sort(member.begin(), member.end(), cmp);
	int line_break = member[floor(m * 1.5) - 1].score;
	int ans = 0;
	for_each(member.begin(), member.end(), [&](Node a) {if (a.score >= line_break) ans++; });
	cout << line_break << " " << ans << endl;
	for (int i = 0; i < ans; i++)
		print(member[i]);
	return 0;
}
