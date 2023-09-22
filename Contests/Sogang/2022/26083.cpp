#include <bits/stdc++.h>
using namespace std;
#define INVALID 0
#define VALID_DATE 1
#define UNSAFE 1
#define SAFE 2
int y, m, d;
int day_of_month[13] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
bool is_leap_year(int y) {
    return y % 400 == 0 || (y % 100 != 0 && y % 4 == 0);
}
bool valid_date(int y, int m, int d) {
    if (m == 0 || m > 12)
        return INVALID;
    int day_limit = day_of_month[m];
    if (m == 2) {
        bool leap = is_leap_year(y);
        day_limit += (int)leap;
    }
    if (d == 0 || d > day_limit)
        return INVALID;
    return VALID_DATE;
}
int safe_detector(int a, int b, int c) {
    if (!valid_date(a, b, c))
        return INVALID;
    if (a < y)
        return UNSAFE;
    else if (a > y)
        return SAFE;
    if (b < m)
        return UNSAFE;
    else if (b > m)
        return SAFE;
    if (c < d)
        return UNSAFE;
    return SAFE;
}
int all_detector(int a, int b, int c) {
    int kor = safe_detector(a, b, c);
    int gree = safe_detector(c, b, a);
    int usa = safe_detector(c, a, b);
    if (kor == INVALID && gree == INVALID && usa == INVALID)
        return INVALID;
    if (kor == UNSAFE || gree == UNSAFE || usa == UNSAFE)
        return UNSAFE;
    return SAFE;
}
int main() {
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(false);
    cin >> y >> m >> d;
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        int a, b, c; cin >> a >> b >> c;
        int res = all_detector(a, b, c);
        if (res == INVALID) {
            cout << "invalid\n";
        } else if (res == SAFE) {
            cout << "safe\n";
        } else
            cout << "unsafe\n";
    }
}
