/*
*	Problem: P1553
*	Author: Insouciant21
*	Time: 2020/8/22 19:18:02
*/

#include <bits/stdc++.h>

using namespace std;

enum type { integer = 1, decimal, fraction, percentage };

type verfiy(string s) {
	if (regex_match(s, regex("\\d+"))) return integer;
	else if (regex_match(s, regex("\\d+\\.\\d+"))) return decimal;
	else if (regex_match(s, regex("\\d+/\\d+"))) return fraction;
	else return percentage;
}

string __erase_zero(string s) {
	s.erase(0, s.find_first_not_of('0'));
	return s;
}

void rev(string &s, type t) {
	stringstream ss;
	switch (t)
	{
	case integer:
	{
		reverse(s.begin(), s.end());
		if (s.size() == 1 && s[0] == '0') s = "0";
		else
			s = __erase_zero(s);
		break;
	}
	case decimal:
	{
		string x, y;
		x = s.substr(0, (s.find('.')));
		y = s.substr(s.find('.') + 1, s.length());
		reverse(x.begin(), x.end());
		y.erase(0, y.find_first_not_of('0'));
		reverse(y.begin(), y.end());
		x.erase(0, x.find_first_not_of('0'));
		s = x + "." + y;
		if (s.front() == '.') s.insert(0, "0");
		if (s.back() == '.') s += '0';
		break;
	}
	case fraction:
	{
		string x, y;
		x = s.substr(0, (s.find('/')));
		y = s.substr(s.find('/'), s.length());
		reverse(x.begin(), x.end());
		reverse(y.begin(), y.end());
		s = to_string(stoll(x)) + "/" + to_string(stoll(y));
		break;
	}
	case percentage:
	{
		string x = s.substr(0, s.length() - 1);
		reverse(x.begin(), x.end());
		s = to_string(stoull(x)) + "%";
		break;
	}
	default:
		break;
	}
}

int main() {
	string s;
	cin >> s;
	type t = verfiy(s);
	rev(s, t);
	cout << s << endl;
	return 0;
}
