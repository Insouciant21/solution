#include <bits/stdc++.h>

using namespace std;

long long t;
long long tmp;
vector<long long> n;
long long cnt = 0;
typedef unsigned long long ull;
typedef long long ll;
// long long sum[11][11] = { {0}, { 0,1,2,3,4,5,6,6,7,8 }, { 0,9, 18, 27, 36, 45, 54, 62, 63, 72
// },{0,81,162,243,324,405,486,566,567,648},{0,729,1458,2187,2916,3645,4374,5102,5103,5832},{0,6561,13122,19683,26244,32805,39366,45926,45927,52488}
// ,{0,59049,118098,177147,236196,295245,354294,413342,413343,472392},{0,1441,1062882,1594323,2125764,2657205,3188646,3720086,3720087,4251528},{0,4782969,9565938,14348907,19131876,23914845,28697814,33480782,33480783,38263752},{0,43046721,86093442,129140163,172186884,215233605,258280326,301327046,301327047,344373768},{0,387420489,774840978}
// };

int main() {
    scanf("%lld", &t);
    n.push_back(1);
    for (long long i = 1; i <= t; i++) {
        scanf("%lld", &tmp);
        n.push_back(tmp);
        // string x = to_string(n.back());
    }
    sort(n.begin(), n.end());
    for (auto i = n.begin() + 1; i != n.end(); i++) {
        if (*i > *(i - 1)) {
            for (int j = *(i - 1); j <= *i; j++) {
                if (to_string(j).find("7") != string::npos)
                    cnt++;
            }
        } else {
            for (int j = *i; j <= *(i - 1); j++) {
                if (to_string(j).find("7") != string::npos)
                    cnt--;
            }
        }
        cout << cnt << endl;
    }
    return 0;
}
