#include <bits/stdc++.h>
using namespace std;
#define NMAX 100100
typedef long long ll;
ll n, q;
vector<ll> adj[NMAX];
ll parent[NMAX];
ll sz[NMAX];
void dfs(ll st, ll par) {
    parent[st] = par;
    for (ll item : adj[st]) {
        if (item != par)
            dfs(item, st);
    }
}
void percolate(ll u, ll x) {
    if (sz[u] >= x) {
        sz[u] += x;
        return;
    }
    x -= sz[u];
    sz[u] *= 2;
    if (adj[u].size() == 1)
        return;
    for (ll nxt : adj[u]) {
        if (nxt != parent[u] && u > 0)
            percolate(nxt, x / (adj[u].size() - 1));
        else if (nxt != parent[u] && u == 0)
            percolate(nxt, x / adj[u].size());
    }
}
int main() {
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    cin >> n >> q;
    for (ll i = 0; i < n - 1; i++) {
        ll u, v;
        cin >> u >> v;
        u--, v--;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    dfs(0, 0);
    for (ll i = 0; i < n; i++) {
        cin >> sz[i];
    }
    for (ll i = 0; i < q; i++) {
        ll mode;
        cin >> mode;
        if (mode == 1) {
            ll u, x;
            cin >> u >> x;
            u--;
            percolate(u, x);
        } else {
            ll u;
            cin >> u;
            u--;
            cout << sz[u] << "\n";
        }
    }
}