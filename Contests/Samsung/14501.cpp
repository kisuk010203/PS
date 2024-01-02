#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;
int main() {
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(false);
    int n;
    cin >> n;
    vector<pii> meetings;
    for (int i = 0; i < n; i++) {
        int a, b;
        cin >> a >> b;
        meetings.push_back({a, b});
    }
    int dp[n][2]; // 0 : do meeting on that day
    dp[n - 1][0] = (meetings[n - 1].first == 1 ? meetings[n - 1].second : 0);
    dp[n - 1][1] = 0;

    for (int i = n - 2; i >= 0; i--) {
        dp[i][1] = max(dp[i + 1][0], dp[i + 1][1]);
        dp[i][0] = (meetings[i].first <= n - i
                        ? meetings[i].second + dp[i + meetings[i].first - 1][1]
                        : 0);
    }
    cout << max(dp[0][0], dp[0][1]);
}
