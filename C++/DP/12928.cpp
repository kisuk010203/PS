#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, s; cin >> n >> s;
    bool dp[n + 1][s + 1];
    memset(dp, false, sizeof(dp));
    dp[1][0] = dp[2][0] = true;
    for (int nn = 3; nn <= n; nn++) {
        for (int ss = 0; ss <= s; ss++) {
            for (int k = 1; k <= nn - 2; k++) {
                int added = (k + 1) * k / 2;
                if (ss - added >= 0) {
                    dp[nn][ss] |= dp[nn - k][ss - added];
                }
            }
        }
    }
    cout << dp[n][s] << "\n";
}