#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define MAX 100100
typedef pair<ll, ll> p;
typedef pair<int, p> point;
int N, T;
point points[MAX];
int ccw(p temp, p a, p b) {
    ll ret =
        temp.first * a.second + a.first * b.second + b.first * temp.second -
        (temp.second * a.first + a.second * b.first + b.second * temp.first);
    if (ret == 0)
        return 0;
    return ((ret > 0) ? 1 : -1);
}
int CCW_two(p a, p b) {
    p temp = points[0].second;
    return ccw(temp, a, b);
}
bool ysort(const p& a, const p& b) {
    if (a.second == b.second)
        return a.first < b.first;
    return a.second < b.second;
}
bool point_ysort(const point& a, const point& b) {
    return ysort(a.second, b.second);
}
bool CCW_twosort(const p& a, const p& b) {
    p temp = points[0].second;
    if (CCW_two(a, b) == 0) {
        ll d1 = (a.first - temp.first) * (a.first - temp.first) +
                (a.second - temp.second) * (a.second - temp.second);
        ll d2 = (b.first - temp.first) * (b.first - temp.first) +
                (b.second - temp.second) * (b.second - temp.second);
        return d1 < d2;
    } else
        return CCW_two(a, b) > 0;
}
bool point_CCW(const point& a, const point& b) {
    return CCW_twosort(a.second, b.second);
}
int main() {
    cin >> T;
    while (T--) {
        cin >> N;
        for (int i = 0; i < N; i++) {
            ll a, b;
            cin >> a >> b;
            points[i] = {i, {a, b}};
        }
        sort(points, points + N, point_ysort);
        sort(points + 1, points + N, point_CCW);
        int last_idx = N - 1;
        for (int i = N - 2; i >= 1; i--) {
            if (CCW_two(points[N - 1].second, points[i].second) == 0)
                last_idx = i;
            else
                break;
        }
        reverse(points + last_idx, points + N);
        for (int i = 0; i < N; i++)
            cout << points[i].first << ' ';
        cout << '\n';
    }
}
