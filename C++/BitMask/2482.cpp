#include <bits/stdc++.h>
using namespace std;
#define MAX 1010
#define MOD (long long)(1e9 + 3)
long long dp[MAX][MAX];
int main() {
    int n, k;
    memset(dp, 0, sizeof(dp));
    cin >> n >> k;
    if (k == 1) {
        cout << n;
        return 0;
    }
    if (2 * k > n) {
        cout << 0;
        return 0;
    }
    for (int i = 0; i < MAX; i++) {
        dp[i][0] = 1;
        dp[i][i] = 1;
    }
    for (int i = 0; i < MAX; i++) {
        for (int j = 0; j < i; j++) {
            dp[i][j] = ((dp[i - 1][j - 1] + dp[i - 1][j]) % MOD);
        }
    }
    long long ans = dp[n - k + 1][n - 2 * k + 1];
    long long ans2 = dp[n - k - 1][n - 2 * k + 1];
    cout << ans << endl;
    cout << (ans - ans2) % MOD;
}
