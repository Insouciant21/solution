#include <bits/stdc++.h>

std::string s, t;
bool win, lose;
int chance;
int left;

void guess(char x) {
    bool find = false;
    for (char &i : s) {
        if (i == x) {
            i = ' ';
            find = true;
            left--;
        }
    }
    if (!find) --chance;
    if (!chance) lose = true;
    if (!left) win = true;
}

void result(int mode) {
    if (mode == 1) puts("You win.");
    else if (mode == 2) puts("You chickened out.");
    else puts("You lose.");
}

int main() {
    while (true) {
        int rnd;
        std::cin >> rnd;
        if (rnd == -1) return 0;
        printf("Round %d\n", rnd);
        std::cin >> s >> t;
        win = false, lose = false;
        chance = 7;
        left = int(s.length());
        for (char i : t) {
            guess(i);
            if (win || lose) break;
        }
        if (win) result(1);
        else if (lose) result(3);
        else result(2);
    }
}
