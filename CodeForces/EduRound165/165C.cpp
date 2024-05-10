#include <bits/stdc++.h>
using namespace std;
int main() {
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(false);
    int T;
    cin >> T;
    while (T--) {
        int n, k;
        cin >> n >> k;
        vector<int> arr(n);
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        int dp[n][k + 1];
        for(int i=0; i<=k; i++){
            dp[0][k] = arr[0];
        }
        for (int i = 1; i < n; i++) {
            dp[n][0] = dp[n - 1][0] + arr[n];
        }
        for (int kk = 1; kk <= k; kk++) {
            for (int i = 1; i < n; i++) {
                dp[i][kk] = max(dp[i - 1][kk] + arr[i], )
            }
        }

    }
}