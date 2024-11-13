#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> pll;
#define INF 1e18
vector<ll> a;
vector<ll> b;
vector<ll> dp;
vector<ll> min_seg;
void update(ll node, ll l, ll r, ll idx) {
    if(l > idx || r < idx) return;
    if(l == r) {
        min_seg[node] = dp[idx];
        return;
    }
    ll mid = (l + r) >> 1;
    update(node << 1, l, mid, idx);
    update(node << 1 | 1, mid + 1, r, idx);
    min_seg[node] = min(min_seg[node << 1], min_seg[node << 1 | 1]);
}
ll query(ll node, ll l, ll r, ll ql, ll qr) {
    if(l > qr || r < ql) return INF;
    if(qr >= r && ql <= l) return min_seg[node];
    ll mid = (l + r) >> 1;
    return min(query(node << 1, l, mid, ql, qr), query(node << 1 | 1, mid + 1, r, ql, qr));
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll t; cin >> t;
    while (t--){
        ll n; cin >> n;
        a.clear();
        b.clear();
        dp.clear();
        min_seg.clear();
        a.resize(n);
        b.resize(n);
        dp.resize(n);
        min_seg.resize(n << 2);
        fill(min_seg.begin(), min_seg.end(), INF);
        for(ll i = 0; i < n; i++) cin >> a[i];
        for(ll i = 0; i < n; i++) cin >> b[i];
        vector<ll> parent[n];
        vector<ll> acc(n);
        acc[0] = a[0];
        for(ll i = 1; i < n; i++) acc[i] = acc[i - 1] + a[i];
        for(ll i = 0; i < n; i++) {
            if(b[i] - 1 > i)
                parent[b[i] - 1].push_back(i);
        }
        for(ll i = 0; i < n; i++) {
            sort(parent[i].begin(), parent[i].end());
        }
        dp[0] = 0;
        update(1, 0, n - 1, 0);
        for(ll i = 1; i < n; i++) {
            ll res = INF;
            for(auto x : parent[i]) {
                res = min(res, query(1, 0, n - 1, x, i - 1) + a[x]);
            }
            dp[i] = res;
            update(1, 0, n - 1, i);
        }
        
        for(ll i = 0; i < n; i ++){
            dp[i] = acc[i] - dp[i];
        }
        ll ans = 0;
        for(ll i = 0; i < n; i++) {
            ans = max(ans, dp[i]);
        }
        cout << ans << "\n";
    }
}