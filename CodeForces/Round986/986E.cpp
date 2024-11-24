#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<long, long> pll;
#define PRIME 998244353
#define NMAX 200200
vector<int> adj[NMAX];
vector<int> par(NMAX);
vector<ll> ans(NMAX);
vector<ll> dist_leaf(NMAX);

void dfs(int cur) {
    // cout << "FOUND " << cur;
    if(adj[cur].size() == 1 && cur != 1) dist_leaf[cur] = 0;
    else {
        for(auto v : adj[cur]) {
            if(par[cur] == v) continue;
            par[v] = cur;
            dfs(v);
        }
        dist_leaf[cur] = NMAX + 2;
        for(auto v : adj[cur]) {
            if(par[v] == cur) {
                // cout << v << " ";
                dist_leaf[cur] = min(dist_leaf[cur], dist_leaf[v] + 1);
            }
        }
    }
}
ll inv(ll x) {
    ll res = 1;
    ll y = PRIME - 2;
    while(y > 0) {
        if(y % 2 == 1) res = (res * x) % PRIME;
        x = (x * x) % PRIME;
        y /= 2;
    }
    return res;
}
void get_ans(int cur, ll denom, ll nom) {
    if(dist_leaf[cur] == 0) ans[cur] = 0L;
    else {
        if(cur != 1){
        nom *= dist_leaf[cur];
        nom %= PRIME;
        denom *= (dist_leaf[cur] + 1);
        denom %= PRIME;}
        ans[cur] = nom * inv(denom);
        ans[cur] %= PRIME;
        for(auto v : adj[cur]) {
            if(par[cur] == v) continue;
            get_ans(v, denom, nom);
        }
    }
}
int main() {
    cin.tie(NULL); ios_base::sync_with_stdio(false);
    int T; cin >> T;
    while(T--) {
        int n; cin >> n;
        for(int i = 0; i < n + 1; i++) {
            adj[i].clear();
            par[i] = 0;
            ans[i] = 0;
        }
        for(int i = 0; i < n- 1;i++){
            int u, v; cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        
        
        dfs(1);
        // for(int i = 1; i <= n; i++) cout << dist_leaf[i] << " ";
        // cout << "\n";
        get_ans(1, 1, 1);
        for(int i = 1; i <= n; i++) cout << ans[i] % PRIME << " ";
        cout << "\n";
    }
}