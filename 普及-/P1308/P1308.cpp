#include <bits/stdc++.h>

using namespace std;

int main() {
	string word, sentence;
	getline(cin, word);
	getline(cin, sentence);
	transform(word.begin(), word.end(), word.begin(), ::tolower);
	transform(sentence.begin(), sentence.end(), sentence.begin(), ::tolower);
	sentence.insert(0, " "); word.insert(0, " ");
	sentence += ' '; word += ' ';
	size_t x = sentence.find(word);
	if (x == string::npos) {
		cout << -1 << endl;
		return 0;
	}
	else {
		long long ans = 0;
		x = 0;
		while (sentence.find(word, x) != string::npos) {
			ans++;
			x = sentence.find(word, x) + 1;
		}
		printf("%lld %d", ans, sentence.find(word));
		return 0;
	}
}
