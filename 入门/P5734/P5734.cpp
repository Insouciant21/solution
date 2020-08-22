#include <iostream>
#include <string>

using namespace std;

int n;
string input;

int main() {
	cin >> n >> input;
	int operation;
	for (int i = 1; i <= n; i++) {
		cin >> operation;
		switch (operation)
		{
		case 1:
		{
			string str;
			cin >> str;
			input += str;
			cout << input << endl;
			break;
		}
		case 2:
		{
			int pos, length;
			cin >> pos >> length;
			input = input.substr(pos, length);
			cout << input << endl;
			break;
		}
		case 3:
		{
			string t1, t2, str;
			int pos;
			cin >> pos >> str;
			t1 = input.substr(0, pos);
			t2 = input.substr(pos, input.length());
			input = t1 + str + t2;
			cout << input << endl;
			break;
		}
		case 4:
		{
			int pos;
			string str;
			cin >> str;
			pos = input.find(str);
			cout << pos << endl;
			break;
		}
		default:
			break;
		}
	}
}