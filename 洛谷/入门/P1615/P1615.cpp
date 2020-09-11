#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

struct timer {
	ll hour, minute, second;
}; 

timer pig, mon;
ll speed;

ll red(timer x, timer y) {
	return (x.hour * 3600 + x.minute * 60 + x.second) - (y.hour * 3600 + y.minute * 60 + y.second);
}

int main() {
	scanf("%lld:%lld:%lld", &pig.hour, &pig.minute, &pig.second);
	scanf("%lld:%lld:%lld", &mon.hour, &mon.minute, &mon.second);
	scanf("%lld",&speed);
	cout << red(mon, pig) * speed;
	return 0;
}
