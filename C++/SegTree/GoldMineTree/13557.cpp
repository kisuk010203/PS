#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
#define INF 1000000000000000
#define NMAX 101111
ll arr[NMAX];
ll pre[NMAX];

ll tmin[NMAX * 4];
ll tmax[NMAX * 4];

struct Node {
    ll sum, lans, rans, ans;
};
Node tree[NMAX * 4];

ll init1(ll s, ll e, ll nod) {
    if (s == e)
        return tmin[nod] = pre[s];
    return tmin[nod] = min(init1(s, (s + e) / 2, nod * 2),
                           init1((s + e) / 2 + 1, e, nod * 2 + 1));
}

ll min_query(ll l, ll r, ll s, ll e, ll nod) {
    if (r < s || l > e)
        return INF;
    if (l <= s && e <= r)
        return tmin[nod];
    return min(min_query(l, r, s, (s + e) / 2, nod * 2),
               min_query(l, r, (s + e) / 2 + 1, e, nod * 2 + 1));
}

ll init2(ll s, ll e, ll nod) {
    if (s == e)
        return tmax[nod] = pre[s];
    return tmax[nod] = max(init2(s, (s + e) / 2, nod * 2),
                           init2((s + e) / 2 + 1, e, nod * 2 + 1));
}

ll max_query(ll l, ll r, ll s, ll e, ll nod) {
    if (r < s || l > e)
        return -INF;
    if (l <= s && e <= r)
        return tmax[nod];
    return max(max_query(l, r, s, (s + e) / 2, nod * 2),
               max_query(l, r, (s + e) / 2 + 1, e, nod * 2 + 1));
}

Node operate(Node a, Node b) {
    Node x;
    x.sum = a.sum + b.sum;
    x.ans = max({a.ans, b.ans, a.rans + b.lans});
    x.lans = max(a.lans, a.sum + b.lans);
    x.rans = max(b.rans, b.sum + a.rans);
    return x;
}

Node init_gold(ll s, ll e, ll nod) {
    if (s == e)
        return tree[nod] = {arr[s], arr[s], arr[s], arr[s]};
    Node a = init_gold(s, (s + e) / 2, nod * 2);
    Node b = init_gold((s + e) / 2 + 1, e, nod * 2 + 1);
    return tree[nod] = operate(a, b);
}

Node sol3(ll l, ll r, ll s, ll e, ll nod) {
    Node x;
    if (r < s || l > e || l > r)
        return x = {-INF, -INF, -INF, -INF};
    if (l <= s && e <= r)
        return tree[nod];
    return operate(sol3(l, r, s, (s + e) / 2, nod * 2),
                   sol3(l, r, (s + e) / 2 + 1, e, nod * 2 + 1));
}

int main() {
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    ll i, j, k, l, m, n;
    cin >> n;
    for (i = 1; i <= n; i++) {
        cin >> arr[i];
        pre[i] = pre[i - 1] + arr[i];
    }
    init1(0, n, 1);
    init2(0, n, 1);
    init_gold(1, n, 1);
    ll x1, x2, y1, y2, t;
    cin >> t;
    while (t--) {
        cin >> x1 >> x2 >> y1 >> y2;
        ll ans1, ans2, ans3;
        ans1 = max_query(y1, y2, 0, n, 1) -
               min_query(x1 - 1, min(y1, x2) - 1, 0, n, 1);
        ans2 = max_query(max(x2, y1), y2, 0, n, 1) -
               min_query(x1 - 1, x2 - 1, 0, n, 1);
        ans3 = sol3(y1, x2, 1, n, 1).ans;
        cout << max({ans1, ans2, ans3}) << "\n";
    }
}
