#include <bits/stdc++.h>

using namespace std;

int n;
vector<int> code;

vector<int> s(string str) {
    vector<int> ans;
    int index = 0;
    for (unsigned long long i = 1; i < str.length(); i++) {
        if (str[i] == ' ') {
            ans.push_back(stoi(str.substr(index, i - index)));
            index = i;
        }
    }
    ans.push_back(stoi(str.substr(index, str.length())));
    return ans;
}

int main() {
    scanf("%d", &n);
    string str;
    getline(cin, str);
    code = s(str);
    bool *s = new bool[n * n];
    for (int i = 0; i < n * n; i++) {
        s[i] = false;
    }
    int index = 0;
    for (unsigned long long i = 0; i < code.size(); i++) {
        if (i % 2 == 0) {
            for (int j = index; j <= index + code[i]; j++) {
                s[j] = false;
            }
        } else {
            for (int j = index; j <= index + code[i]; j++) {
                s[j] = true;
            }
        }
        index += code[i];
    }
    for (int i = 0; i < n * n; i++) {
        cout << s[i];
        if ((i + 1) % n == 0)
            cout << endl;
    }
    return 0;
}
