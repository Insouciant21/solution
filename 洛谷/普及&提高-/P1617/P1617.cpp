/*
*  Problem: P1617
*  Author: Insouciant21
*  Time: 2020/9/5 13:53:43
*  Status: Accepted
*/

#include <bits/stdc++.h>

using namespace std;
string s[100];
string n;

int main() {
	cin >> n;
	int num = stoi(n);
	s[1] = "one";
	s[2] = "two";
	s[3] = "three";
	s[4] = "four";
	s[5] = "five";
	s[6] = "six";
	s[7] = "seven";
	s[8] = "eight";
	s[9] = "nine";
	s[10] = "ten";
	s[11] = "eleven";
	s[12] = "twelve";
	s[13] = "thirteen";
	s[14] = "fourteen";
	s[15] = "fifteen";
	s[16] = "sixteen";
	s[17] = "seventeen";
	s[18] = "eighteen";
	s[19] = "nineteen";
	s[20] = "twenty";
	s[30] = "thirty";
	s[40] = "fourty";
	s[50] = "fifty";
	s[60] = "sixty";
	s[70] = "seventy";
	s[80] = "eighty";
	s[90] = "ninety";
	if (num < 100) {
		if (num == 0) cout << "zero" << endl;
		else if (num <= 10 || num % 10 == 0) cout << s[num] << endl;
		else if (num > 10 && num < 20) cout << s[num] << endl;
		else cout << s[num - num % 10] << " " << s[num % 10] << endl;
	}
	else if (num < 1000) {
		cout << s[num / 100] << " hundred ";
		if (num % 100 == 0) return 0;
		if (num % 100 <= 10) cout << "and " << s[num % 100] << endl;
		else if (num % 100 > 10 && num % 100 < 20) cout << s[num % 100] << endl;
		else cout << s[(num % 100) - (num % 100) % 10] << " " << s[num % 10] << endl;
	}
	else {
		cout << s[num / 1000] << " thousand ";
		if (num % 1000 == 0) return 0;
		if (num % 1000 < 100) {
			cout << "and ";
			if (num % 1000 <= 10 || (num % 1000) % 10 == 0) cout << s[num % 1000] << endl;
			else if ((num % 1000) > 10 && (num % 1000) < 20) cout << s[num % 1000] << endl;
			else cout << s[(num % 1000) / 10 * 10] << " " << s[(num % 1000) % 10] << endl;
		}
		else {
			cout << s[(num % 1000) / 100] << " hundred ";
			if ((num % 1000) % 100 == 0) return 0;
			if ((num % 1000) % 100 <= 10) cout << "and " << s[(num % 1000) % 100] << endl;
			else if ((num % 1000) % 100 > 10 && (num % 1000) % 100 < 20) cout << s[(num % 1000) % 100] << endl;
			else cout << s[((num % 1000) % 100) - ((num % 1000) % 100) % 10] << " " << s[(num % 1000) % 10] << endl;
		}
	}
	return 0;
}
