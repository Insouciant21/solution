#include <cstdio>

int main() {
    /* generator
    set<long long> u;
    u.insert(1);
    for (auto i : u) {
        u.insert(i * 2);
        u.insert(i * 3);
        u.insert(i * 5);
        if (u.size() > 2000) break;
    }
    int cnt = 0;
    for (auto i = u.begin(); i != u.end(); i++, cnt++)
        if (cnt == 1499) printf("The 1500'th ugly number is %d.\n", *i);
    */
    puts("The 1500'th ugly number is 859963392.");
    return 0;
}
