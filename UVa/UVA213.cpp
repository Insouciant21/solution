#include <bits/stdc++.h>

using namespace std;

char codes[8][128];

void make_table(string str) {
    int q = 0;
    for (int i = 1; q < str.length(); i++)
        for (int j = 0; j < (1 << i) - 1 && q < str.length(); j++) codes[i][j] = str[q++];
}

int main() {
    vector<string> allCodes;
    string temp;
    while (getline(cin, temp) && !temp.empty()) allCodes.push_back(temp);
    for (int row = 0; row < allCodes.size();) {
        string header = allCodes[row++];
        make_table(header);
        string ans;
        int col = 0;
        while (true) {
            bitset<3> p(0);
            for (int i = 0; i < 3; i++) {
                if (col == allCodes[row].length()) row++, col = 0;
                p[2 - i] = allCodes[row][col++] - '0';
            }
            int len = int(p.to_ulong());
            if (len == 0) {
                row++;
                break;
            }
            while (true) {
                bitset<10> c(0);
                for (int i = 0; i < len; i++) {
                    if (col == allCodes[row].length()) row++, col = 0;
                    c[len - 1 - i] = allCodes[row][col++] - '0';
                }
                int k = int(c.to_ulong());
                if (k == (1 << len) - 1) break;
                ans += codes[len][k];
            }
        }
        cout << ans << endl;
    }
    return 0;
}
