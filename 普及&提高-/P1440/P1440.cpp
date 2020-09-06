/* 
*  Problem: P1440
*  Author: Insouciant21
*  Time: 2020/9/6 20:49:50
*  Status: Time Limit Exceeded 80
*/

#include <bits/stdc++.h>

using namespace std;

priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>> >q;

int main() {
	ios::sync_with_stdio(false);
	int n, k;
	cin >> n >> k;
	cout << 0 << endl;
	for (int i = 1,t; i < n && cin >> t; i++) {
		q.push(make_pair(t,i));
		pair<int, int>l = q.top();
		while (l.second <= i - k) {
			q.pop(); l = q.top();
		}
		cout << l.first << endl;
	}
	return 0;
}
