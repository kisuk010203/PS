#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define INF (ll)1e9
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n, m, k; cin >> n >> m >> k;
    int st, dest; cin >> st >> dest;
    st--; dest--;

    vector<pair<int, int>> adj[n];
    for (int i = 0; i < m; i++) {
        int u, v, w; cin >> u >> v >> w;
        u--; v--;
        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
    }

    ll dp[n][n];
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            dp[i][j] = (ll)1e9;
        }
    }
    dp[0][st] = 0;
    for (int len_path = 1; len_path < n; len_path++) { //length of path
        for (int en = 0; en < n; en++) {
            for (auto edge : adj[en]) {
                auto [u, w] = edge;
                dp[len_path][en] = min(
                    dp[len_path][en],
                    dp[len_path - 1][u] + w
                );
            }
        }
    }

    ll cost = 0;
    for (int i = 0; i <= k; i++) {
        if (i > 0) {
            int c; cin >> c;
            cost += c;
        }
        ll ans = 1e10;
        for (int i = 0; i < n; i++) {
            ans = min(ans, dp[i][dest] + cost * i);
        }
        cout << ans << "\n";
    }

}