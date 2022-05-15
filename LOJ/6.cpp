#include "interaction.h"
#include <bits/stdc++.h>

using namespace std;

int main() {
    vector<int> ans;
    int T = get_num();
    ans.resize(T);
    for (int i = 0; i < T; i++) {
        int l = 0, r = 1000000;
        int m = (l + r) / 2;
        int s = 0;
        while (s = guess(i, m)) {
            if (s == 1) r = m - 1;
            if (s == -1) l = m + 1;
            m = (l + r) / 2;
        }
        ans[i] = m;
    }
    submit(ans);
}
