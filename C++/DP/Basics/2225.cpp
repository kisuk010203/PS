#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define MOD (ll)1e9

int main() {
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(false);

    int n, k;
    cin >> n >> k;
    int dp[n + 1][k + 1];
    memset(dp, 0, sizeof(dp));
    dp[0][0] = 1;
    for (int i = 0; i <= n; i++) {
        for (int kk = 1; kk <= k; kk++) {
            for (int j = 0; j <= i; j++) {
                dp[i][kk] += dp[j][kk - 1];
                dp[i][kk] %= MOD;
            }
        }
    }
    cout << dp[n][k];
}
