#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define all(v) v.begin(), v.end()
#define rep(i, a, b) for(ll i = a; i < b; i++)
#define repd(i, a, b) for(ll i = a; i >= b; i--)
#define each(a, b) for(auto& a : b)
typedef pair<ll, ll> pll;
#define INF 3000000
int main() {
    cin.tie(NULL); ios_base::sync_with_stdio(false);
    int T; cin >> T;
    while(T--) {
        int n, m; cin >> n >> m;
        vector<ll> a(n + 1), b(m + 1);
        vector<ll> acc_a(n + 1);
        rep(i, 1, n + 1) cin >> a[i];
        rep(i, 1, m + 1) cin >> b[i];
        acc_a[0] = 0;
        rep(i, 1, n + 1) acc_a[i] = acc_a[i - 1] + a[i];
        ll ans = 0;
        ll dp[n + 1][m + 1];
        dp[n][m] = (a[n] > b[m]) ? INF : 0;
        repd(t, n, 1) {
            repd(k, m, 1) {
                if(t == n && k == m) continue;
                dp[t][k] = (k == m) ? INF : dp[t][k + 1];
                // cout << t << " " << k << " " << dp[t][k] << " ";
                int get_t = upper_bound(all(acc_a), b[k] + acc_a[t-1]) - acc_a.begin();
                // cout << get_t << "\n";
                if(get_t == n + 1) {
                    dp[t][k] = min(dp[t][k], m - k);
                    continue;
                }
                dp[t][k] = min(dp[t][k], m - k + dp[get_t][k]);
            }
        }
        // rep(k, 1, m + 1) {
        //     rep(t, 1, n + 1)
        //     //     cout << t << " " << k << " " << dp[t][k] << "\n";
        //     // cout << "\n";
        // }
        if (dp[1][1] >= INF) dp[1][1] = -1;
        cout << dp[1][1] << "\n";
    }
}