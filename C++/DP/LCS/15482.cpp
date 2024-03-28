#include <bits/stdc++.h>
using namespace std;
int main() {
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(false);
    string a, b;
    cin >> a >> b;
    int dp[a.size() / 3 + 1][b.size() / 3 + 1];
    memset(dp, 0, sizeof(dp));
    for (int i = 1; i <= a.size() / 3; i++) {
        for (int j = 1; j <= b.size() / 3; j++) {
            if (a[(i - 1) * 3] == b[(j - 1) * 3] &&
                a[(i - 1) * 3 + 1] == b[(j - 1) * 3 + 1] &&
                a[(i - 1) * 3 + 2] == b[(j - 1) * 3 + 2]) {
                dp[i][j] =
                    max(dp[i - 1][j - 1] + 1, max(dp[i - 1][j], dp[i][j - 1]));
            } else {
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
    }
    cout << dp[a.size() / 3][b.size() / 3] << "\n";
}