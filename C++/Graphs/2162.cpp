#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> p;
typedef pair<p, p> segment;
#define MAX 3000
int root[MAX];
int cnt;
int sz[MAX];
segment line[MAX];
int find(int x) {
    if (root[x] == x)
        return x;
    return root[x] = find(root[x]);
}
void unite(int x, int y) {
    x = find(x);
    y = find(y);
    if (x != y) {
        if (sz[x] < sz[y])
            swap(x, y);
        sz[x] += sz[y];
        root[y] = x;
        cnt--;
    }
    root[y] = x;
}
int ccw(p a, p b, p c) {
    ll ans = a.first * b.second + b.first * c.second + c.first * a.second -
             a.second * b.first - b.second * c.first - c.second * a.first;
    if (ans == 0)
        return 0;
    return ((ans > 0) ? 1 : -1);
}
bool intersection(segment a, segment b) {
    int ccw1 =
        ccw(a.first, a.second, b.first) * ccw(a.first, a.second, b.second);
    int ccw2 =
        ccw(b.first, b.second, a.first) * ccw(b.first, b.second, a.second);
    if (ccw1 != 1 && ccw2 != 1) {
        if (ccw1 == 0 && ccw2 == 0) {
            int flag = 0;
            int d = min(a.first.first, a.second.first),
                e = max(a.first.first, a.second.first);
            int f = min(b.first.first, b.second.first),
                g = max(b.first.first, b.second.first);
            if (d < f)
                flag = (e >= f);
            else if (d == f)
                flag = 1;
            else
                flag = (g >= d);

            d = min(a.first.second, a.second.second),
            e = max(a.first.second, a.second.second);
            f = min(b.first.second, b.second.second),
            g = max(b.first.second, b.second.second);
            if (d < f)
                flag = flag && (e >= f);

            else if (d == f)
                flag = flag && 1;

            else
                flag = flag && (g >= d);
            return flag;
        }
        return 1;
    }
    return 0;
}
int main(int argc, char const* argv[]) {
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(false);
    int n;
    cin >> n;
    cnt = n;
    for (int i = 0; i < MAX; i++) {
        sz[i] = 1;
        root[i] = i;
    }
    for (int i = 0; i < n; i++) {
        int a, b, c, d;
        cin >> a >> b >> c >> d;
        line[i] = make_pair(make_pair(a, b), make_pair(c, d));
    }
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; i < n; i++) {
            if (intersection(line[i], line[j])) {
                unite(i, j);
            }
        }
    }
    cout << cnt << endl;
    int res = -1;
    for (auto item : sz) {
        res = max(res, item);
    }
    cout << res;

    return 0;
}
