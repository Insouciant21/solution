#include <bits/stdc++.h>

using namespace std;

bool pic[50][50];

string s;
int ans = 0;

void draw(int &pos, int r, int c, int w) {
    char g = s[pos++];
    if (g == 'p') {
        draw(pos, r, c + w / 2, w / 2);
        draw(pos, r, c, w / 2);
        draw(pos, r + w / 2, c, w / 2);
        draw(pos, r + w / 2, c + w / 2, w / 2);
    }
    if (g == 'f') {
        for (int i = r; i < r + w; i++) {
            for (int j = c; j < c + w; j++) {
                if (!pic[i][j]) {
                    ans++;
                    pic[i][j] = true;
                }
            }
        }
    }
}

int main() {
    int n;
    cin >> n;
    while (n--) {
        ans = 0;
        memset(pic, 0, sizeof pic);
        for (int i = 0; i < 2; i++) {
            cin >> s;
            int g = 0;
            draw(g, 0, 0, 32);
        }
        cout << "There are " << ans << " black pixels." << endl;
    }
    return 0;
}
