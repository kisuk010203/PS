#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> p;
typedef pair<p, p> seg;
typedef pair<seg, ll> line;
#define MAX 2500
int N;
line lines[MAX];
bool comparator(const line& a, const line& b) {
    return a.second < b.second;
}
int ccw(p a, p b, p c) {
    ll res = a.first * b.second + b.first * c.second + c.first * a.second -
             (a.second * b.first + b.second * c.first + c.second * a.first);
    return (res > 0 ? 1 : -1);
}
bool intersection(seg a, seg b) {
    int ccw1 =
        ccw(a.first, a.second, b.first) * ccw(a.first, a.second, b.second);
    int ccw2 =
        ccw(b.first, b.second, a.first) * ccw(b.first, b.second, a.second);
    return (ccw1 == -1) && (ccw2 == -1);
}
int main(int argc, char const* argv[]) {
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(false);
    cin >> N;
    for (int i = 0; i < N; i++) {
        ll sx, sy, ex, ey, w;
        cin >> sx >> sy >> ex >> ey >> w;
        lines[i] =
            make_pair(make_pair(make_pair(sx, sy), make_pair(ex, ey)), w);
    }
    stable_sort(lines, lines + N, comparator);
    ll res = 0;
    for (int i = 0; i < N; i++) {
        ll mul = 1;
        for (int j = i + 1; j < N; j++)
            if (intersection(lines[i].first, lines[j].first))
                mul++;
        res += mul * lines[i].second;
    }
    cout << res;
    return 0;
}
