#include <bits/stdc++.h>

using namespace std;

string pending;

int cnt(string str, string sub) {
    int num = 0;
    for (size_t i = 0; (i = str.find(sub, i)) != std::string::npos; num++, i++)
        ;
    return num;
}

int main() {
    cin >> pending;
    int len = pending.length();
    pending.erase(remove(pending.begin(), pending.end(), '.'), pending.end());
    regex_replace(pending, regex("b([^o][^y])"), "boy$1");
    regex_replace(pending, regex("([^b])o([^y])"), "$1boy$2");
    regex_replace(pending, regex("([^b][^o])y"), "$1boy");
    regex_replace(pending, regex("g([^i][^r][^l])"), "girl$1");
    regex_replace(pending, regex("([^g])i([^r][^l])"), "$1girl$2");
    regex_replace(pending, regex("([^g][^i])r([^l])"), "$1girl$2");
    regex_replace(pending, regex("([^g][^i][^r])l"), "$1girl");
    cout << pending << endl;
    cout << cnt(pending, "boy") << endl << cnt(pending, "girl") << endl;
    return 0;
}
