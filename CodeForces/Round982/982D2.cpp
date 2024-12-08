#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define all(v) v.begin(), v.end()
#define rep(i, a, b) for(ll i = a; i < b; i++)
#define repd(i, a, b) for(ll i = a; i >= b; i--)
#define each(a, b) for(auto& a : b)
typedef pair<ll, ll> pll;
#define INF 3000000
#define MOD 1000000007
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
        ll dp[n + 1][m + 1];
        ll ans[n + 1][m + 1];
        dp[n][m] = (a[n] > b[m]) ? INF : 0;
        ans[n][m] = (a[n] > b[m]) ? 0 : 1;
        repd(k, m, 1) {
            vector<ll> rev_dp(n + 1);
            fill(all(rev_dp), -INF);
            vector<ll> acc_ans(n + 1); // acc_ans[i] = ans[i][k] + ... + ans[n][k]
            fill(all(acc_ans), 0);
            acc_ans[n] = ans[n][k] ? k == m : 0;
            repd(t, n, 1) {
                if(t == n && k == m) continue;
                dp[t][k] = (k == m) ? INF : dp[t][k + 1];
                ans[t][k] = 0;
                auto get_t = upper_bound(all(acc_a), b[k] + acc_a[t-1]) - acc_a.begin();
                if(get_t == n + 1) {
                    dp[t][k] = min(dp[t][k], m - k);
                    if(k != m && dp[t][k] == dp[t][k + 1])
                        ans[t][k] = ans[t][k + 1];
                    if(dp[t][k] == m - k) {
                        cout << "Case 2 : " << t << k << " ";
                        auto get_lower_t = lower_bound(all(rev_dp), 0) - rev_dp.begin();
                        ans[t][k] = (acc_ans[get_lower_t] + ans[t][k] + MOD) % MOD;
                        cout << get_lower_t << acc_ans[get_lower_t] << "\n";
                    }
                    if(t != n){
                        acc_ans[t] = acc_ans[t + 1] + ans[t][k];
                        acc_ans[t] %= MOD;
                    }
                    rev_dp[t] = -dp[t][k];
                    continue;
                }
                dp[t][k] = min(dp[t][k], m - k + dp[get_t][k]);
                rev_dp[t] = -dp[t][k];
                if(k != m && dp[t][k] == dp[t][k + 1]) {
                    ans[t][k] = ans[t][k + 1];
                }
                if(dp[t][k] == m - k + dp[get_t][k]) {
                    cout << "Case 2 : " << t << k << " " ;
                    auto get_lower_t = lower_bound(all(rev_dp), -dp[get_t][k]) - rev_dp.begin();
                    cout << get_lower_t << acc_ans[get_lower_t] << "\n";
                    ans[t][k] = (acc_ans[get_lower_t] + ans[(int)t][k] + MOD) % MOD;
                    if(get_t != n) {
                        ans[(int)t][k] = (ans[(int)t][k] - acc_ans[get_t + 1] + MOD) % MOD;
                    }
                }
                if(t != n)
                    acc_ans[(int)t] = acc_ans[t + 1] + ans[(int)t][k];
            }
        }
        if (dp[1][1] >= INF){
            cout << "-1\n"; continue;
        }
        rep(k, 1, m + 1) {
            rep(t, 1, n + 1)
                cout << t << " " << k << " " << ans[t][k] << "\n";
            cout << "\n";
        }
        cout << dp[1][1] << " ";
        cout << ans[1][1] << "\n";


    }
}