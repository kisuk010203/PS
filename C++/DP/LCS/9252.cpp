#include <bits/stdc++.h>
using namespace std;
int main() {
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(false);
    string a, b;
    cin >> a >> b;
    int dp[a.size() + 1][b.size() + 1];
    memset(dp, 0, sizeof(dp));
    for (int i = 1; i <= a.size(); i++) {
        for (int j = 1; j <= b.size(); j++) {
            if (a[i - 1] == b[j - 1]) {
                dp[i][j] =
                    max(dp[i][j - 1], max(dp[i - 1][j - 1] + 1, dp[i - 1][j]));
            } else {
                dp[i][j] = max(dp[i][j - 1], dp[i - 1][j]);
            }
        }
    }
    cout << dp[a.size()][b.size()] << "\n";
    vector<char> ans;
    int i = a.size(), j = b.size();
    while (dp[i][j] > 0) {
        if (dp[i][j] == dp[i - 1][j]) {
            i--;
        } else if (dp[i][j] == dp[i][j - 1]) {
            j--;
        } else {
            ans.push_back(a[i - 1]);
            i--;
            j--;
        }
    }
    while (!ans.empty()) {
        cout << ans.back();
        ans.pop_back();
    }
}