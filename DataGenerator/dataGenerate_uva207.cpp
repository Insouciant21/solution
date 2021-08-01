#include <bits/stdc++.h>

using namespace std;

int main() {
    freopen("uva207.in", "w", stdout);
    random_device rd;
    mt19937_64 gen(rd());
    uniform_int_distribution<> g(1, 2147483647);
    uniform_real_distribution<double> p(3e5, 9e6);
    uniform_int_distribution<int> l(1, 142);
    int kase = g(gen) % 20;
    cout << kase << endl;
    for (int k = 0; k < kase; k++) {
        cout << endl;
        cout << fixed << setprecision(2) << p(gen) << endl;
        int gt = 10000;
        for (int i = 0; i < 69; i++) {
            int h = l(gen);
            while (gt - h < 0) h = l(gen);
            gt -= h;
            cout << fixed << setprecision(4) << h / 100.0 << endl;
        }
        cout << gt / 100.0 << endl;
        cout << 140 << endl;
        for (int i = 0; i < 140; i++) {
            string s = "P";
            s += to_string(i);
            if (g(gen) % 20 < 4)
                s += "*";
            while (s.length() != 20) s += " ";
            cout << s;
            for (int j = 0; j < 4; j++) {
                if (g(gen) % 40 == 0) {
                    cout << " DQ";
                    break;
                }
                else
                    cout << setw(3) << g(gen) % 10;
            }
            cout << endl;
        }
    }
}
