#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define MOD 1000000007L
#define NMAX 202020
unordered_map<ll, ll> idx;
vector<ll> adj[NMAX];
bool visited[NMAX];
ll idx_start = 0;
ll ans = 1L;
ll power(ll base, ll expo) {
    if (expo == 0)
        return 1;
    ll mid = power(base, expo >> 1);
    mid = (mid * mid) % MOD;
    if (expo & 1) {
        return (mid * base) % MOD;
    }
    return mid;
}
void add_or_create_to_map(ll item) {
    if (idx.find(item) == idx.end()) {
        idx[item] = idx_start;
        idx_start++;
    }
}
ll dfs(ll start, ll parent) {
    ll res = 1;
    visited[start] = true;
    for (auto nxt : adj[start]) {
        if (visited[nxt] && nxt != parent) {
            cout << 0;
            exit(0);
        }
        if (!visited[nxt])
            res += dfs(nxt, start);
    }
    return res;
}
int main() {
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    ll n, m;
    cin >> n >> m;

    for (ll i = 0; i < m; i++) {
        ll x, y;
        cin >> x >> y;
        add_or_create_to_map(x);
        add_or_create_to_map(y);
        adj[idx[x]].push_back(idx[y]);
        adj[idx[y]].push_back(idx[x]);
    }
    if (m >= n) {
        cout << 0;
        return 0;
    }
    memset(visited, false, sizeof(visited));
    for (ll i = 0; i < idx_start; i++) {
        if (!visited[i]) {
            ans = (ans * dfs(i, i)) % MOD;
        }
    }
    if (m == n - 1)
        cout << 1 << "\n";
    else {
        ans = (ans * power(n, n - m - 2)) % MOD;
        cout << ans << "\n";
    }
}