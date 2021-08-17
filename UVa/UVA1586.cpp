#include <bits/stdc++.h>

double getMess(char ch) {
    switch (ch) {
        case 'C': return 12.01;
        case 'H': return 1.008;
        case 'O': return 16.00;
        case 'N': return 14.01;
        default: return 0.00;
    }
}

int main() {
    int n;
    scanf("%d", &n);
    while (n--) {
        char s[88];
        scanf("%s", s);
        double molar = 0;
        for (int i = 0; i < strlen(s); i++) {
            if (s[i] == 'C' || s[i] == 'H' || s[i] == 'O' || s[i] == 'N') {
                int quantity = 0;
                if (i + 1 == strlen(s) || (s[i + 1] == 'C' || s[i + 1] == 'H' || s[i + 1] == 'O' || s[i + 1] == 'N'))
                    quantity = 1;
                else {
                    for (int j = i + 1; j < strlen(s); j++) {
                        if (s[j] >= '0' && s[j] <= '9') quantity = quantity * 10 + s[j] - '0';
                        else break;
                    }
                }
                molar += quantity * getMess(s[i]);
            }
        }
        printf("%.3lf\n", molar);
    }
    return 0;
}
