#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> p;
#define MOD 1000000007
int find(ll *parent, int x) {
    if (!parent[x])
        return x;

    int y = x;
    while (parent[y]) {
        y = parent[y];
    }
    while (parent[x]) {
        int parent_x = parent[x];
        parent[x] = y;
        x = parent_x;
    }
    return y;
}
int main() {
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(false);
    int n, q;
    cin >> n >> q;
    ll fibo[n + 1];
    fibo[0] = fibo[1] = 1;
    for (int i = 2; i < n + 1; i++) {
        fibo[i] = fibo[i - 1] + fibo[i - 2];
        fibo[i] %= MOD;
    }
    vector<p> queries;
    for (int i = 0; i < q; i++) {
        ll l, r;
        cin >> l >> r;
        queries.push_back({l - 1, r - 1});
    }

    ll ans[n];
    ll parent[n + 1];
    memset(ans, 0, sizeof(ans));
    memset(parent, 0, sizeof(parent));

    for (int i = queries.size() - 1; i >= 0; i--) {
        ll l = queries[i].first, r = queries[i].second;
        ll idx = l;
        while (true) {
            if (!ans[idx]) {
                ans[idx] = fibo[idx - l + 1];
            }
            idx = find(parent, idx) + 1;
            if (idx <= r)
                parent[idx - 1] = idx;
            else
                break;
        }
    }

    for (int i = 0; i < n; i++) {
        cout << ans[i] << " ";
    }
}
