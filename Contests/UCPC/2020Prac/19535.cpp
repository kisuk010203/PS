#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll comb3(ll n) {
    return n * (n - 1) * (n - 2) / 6;
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n; cin >> n;
    vector<int> adj[n + 1];
    for(int i = 0; i < n - 1; i++) {
        int u, v; cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    ll d = 0, g = 0;
    for(int i = 1; i <= n; i++) {
        g += comb3(adj[i].size());
    }
    for(int i = 1; i<=n; i++) {
        for(int j : adj[i]) {
            d+= (adj[i].size() - 1) * (adj[j].size() - 1);
        }
    }
    d /=2;
    if(d > 3 * g) {
        cout << "D\n";
    } else if(d < 3 * g) {
        cout << "G\n";
    } else {
        cout << "DUDUDUNGA\n";
    }
}