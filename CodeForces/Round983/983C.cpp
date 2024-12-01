#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<long, long> pll;
int main() {
    cin.tie(NULL); ios_base::sync_with_stdio(false);
    int T; cin >> T;
    while(T--) {
        ll n; cin >> n;
        vector<ll> v(n);
        vector<ll> dp(n);
        for(int i = 0; i < n; i++) cin >> v[i];
        sort(v.begin(), v.end());
        dp[n-2] = n-1;
        ll dp_idx = n-3;
        ll ans_idx = n - 1;
        while(dp_idx >= 0) {
            if(v[dp_idx] + v[dp_idx + 1] > v[ans_idx]) {
                dp[dp_idx] = ans_idx;
                dp_idx--;
            } else {
                ans_idx--;
            }
        }
        ll min_ans = n - 2;
        for(ll i = 0; i < n - 2; i++) {
            min_ans=  min(min_ans, n - (dp[i] - i + 1L));
        }
        cout << min_ans << "\n";
    }
}