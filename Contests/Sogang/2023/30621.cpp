#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
void input(ll n, vector<ll>& name) {
    for (ll i = 0; i < n; i++) {
        cin >> name[i];
    }
}
int main() {
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(false);

    ll n;
    cin >> n;
    vector<ll> times(n);
    vector<ll> before(n);
    vector<ll> weight(n);

    input(n, times);
    input(n, before);
    input(n, weight);

    ll called_dp[n];      // i is called
    ll not_called_dp[n];  // i is not called
    memset(called_dp, 0, sizeof(called_dp));
    memset(not_called_dp, 0, sizeof(not_called_dp));

    called_dp[0] = weight[0];
    not_called_dp[0] = 0;

    for (ll i = 1; i < n; i++) {
        not_called_dp[i] = max(not_called_dp[i - 1], called_dp[i - 1]);
        ll idx = lower_bound(times.begin(), times.end(), times[i] - before[i]) -
                 times.begin();
        called_dp[i] = not_called_dp[idx] + weight[i];
    }

    cout << max(not_called_dp[n - 1], called_dp[n - 1]);
}
