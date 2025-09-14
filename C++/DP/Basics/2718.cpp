#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    constexpr size_t SIZE = 100005;
    int T; cin >> T;
    uint32_t dp[SIZE][3];
    dp[1][0] = 1; dp[2][0] = 5;
    dp[0][1] = 1, dp[1][1] = 2, dp[2][1] = 7;
    dp[0][2] = 1, dp[1][2] = 1, dp[2][2] = 6;

    for (int i = 3; i < SIZE; i++) {
        dp[i][0] = dp[i - 1][0] + 2 * dp[i - 2][1] + dp[i - 2][0] + dp[i - 2][2];
        dp[i][1] = dp[i][0] + dp[i - 1][1];
        dp[i][2] = dp[i][0] + dp[i - 2][2];
    }
     

    while(T--) {
        int n; cin >> n;
        cout << dp[n][0] << "\n";
    }
    
}