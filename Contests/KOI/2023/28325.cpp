#include <bits/stdc++.h>
using namespace std;
int main() {
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(false);
    int n;
    cin >> n;
    vector<long long> degrees(n);
    for (int i = 0; i < n; i++) {
        cin >> degrees[i];
    }

    long long dp[n + 1][4]; // dp[i][j] means that 1 ... i is done, with mode j
    memset(dp, 0, sizeof(dp));
    dp[1][0] = degrees[0];
    dp[1][1] = LONG_LONG_MIN;
    dp[1][2] = LONG_LONG_MIN;
    dp[1][3] = 1;

    for (int i = 2; i <= n; i++) {
        dp[i][0] = max(dp[i - 1][0], dp[i - 1][1]) + degrees[i - 1];
        dp[i][1] = dp[i - 1][0] + 1;
        dp[i][2] = max(dp[i - 1][2], dp[i - 1][3]) + degrees[i - 1];
        dp[i][3] = dp[i - 1][2] + 1;
    }

    long long ans = max(max(dp[n][0], dp[n][1]), dp[n][2]);
    cout << ans << "\n";
}
