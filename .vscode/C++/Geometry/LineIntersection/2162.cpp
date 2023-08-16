#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> p;
typedef pair<p, p> segment;
#define MAX 3030
int root[MAX];
int sz[MAX];
segment lines[MAX];
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
        root[y] = x;
        sz[x] += sz[y];
    }
}
int ccw(p a, p b, p c) {
    ll ret = a.first * b.second + b.first * c.second + c.first * a.second -
             (a.second * b.first + b.second * c.first + c.second * a.first);
    if (ret == 0)
        return 0;
    return (ret > 0 ? 1 : -1);
}
bool intersection(segment a, segment b) {
    int ccw1 =
        ccw(a.first, a.second, b.first) * ccw(a.first, a.second, b.second);
    int ccw2 =
        ccw(b.first, b.second, a.first) * ccw(b.first, b.second, a.second);
    if (ccw1 == 1 || ccw2 == 1)
        return false;
    if (ccw1 != 0 || ccw2 != 0)
        return true;
    bool flag = false;

    int d = min(a.first.first, a.second.first),
        e = max(a.first.first, a.second.first);
    int f = min(b.first.first, b.second.first),
        g = max(b.first.first, b.second.first);
    if (d < f)
        flag = (e >= f);
    else if (d == f)
        flag = true;
    else
        flag = (g >= d);

    d = min(a.first.second, a.second.second),
    e = max(a.first.second, a.second.second);
    f = min(b.first.second, b.second.second),
    g = max(b.first.second, b.second.second);
    if (d < f)
        flag &= (e >= f);
    else if (d > f)
        flag &= (g >= d);

    return flag;
}
int main() {
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(false);
    int N;
    cin >> N;
    for (int i = 0; i < N; i++) {
        ll a, b, c, d;
        cin >> a >> b >> c >> d;
        lines[i] = {{a, b}, {c, d}};
        root[i] = i;
        sz[i] = 1;
    }
    for (int i = 0; i < N; i++) {
        for (int j = i + 1; j < N; j++) {
            if (intersection(lines[i], lines[j]))
                unite(i, j);
        }
    }
    set<int> s;
    int ret = -1;
    for (int i = 0; i < N; i++) {
        s.insert(find(root[i]));
        ret = max(ret, sz[find(root[i])]);
    }
    cout << s.size() << '\n';
    cout << ret << '\n';
}