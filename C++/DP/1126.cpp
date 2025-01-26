#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    
    int n; cin >> n;
    vector<int> v(n);
    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }
    
    int dp[500000 + 1]; // dp[i] = max val of larger tower when diff is i
    fill(dp, dp + 500001, -1);
    dp[0] = 0;
    for(int i = 0; i < n; i++) {
        int new_dp[500000 + 1];
        copy(begin(dp), end(dp), begin(new_dp));
        int target = v[i];
        for(int j = 0; j <= 500000; j++) {
            if(j >= target && dp[j - target] != -1) // bigger to bigger
                new_dp[j] = max(new_dp[j], dp[j - target] + target);
            if(j <= 500000 - target && dp[j + target] != -1)
                new_dp[j] = max(new_dp[j], dp[j + target]);
            if(j <= target && dp[target - j] != -1) 
                new_dp[j] = max(new_dp[j], dp[target - j] + j);
        }
        copy(begin(new_dp), end(new_dp), begin(dp));
    }
    cout << (dp[0] == 0 ? -1 : dp[0]) << "\n";
}