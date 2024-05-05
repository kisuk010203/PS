//https://codeforces.com/contest/1946/problem/C
#include <bits/stdc++.h>
        using namespace std;
typedef long long ll;
#define MOD 1000000007
ll get_power_of_2(int exp) {
    if (exp == 0)
        return 1;
    ll half = get_power_of_2(exp / 2);
    ll result = (half * half) % MOD;
    if (exp % 2 == 1)
        result = (result * 2) % MOD;
    return result;
}
int main() {
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(false);
    int T;
    cin >> T;
    while (T--) {
        int n, k;
        cin >> n >> k;
        vector<ll> v(n);
        vector<ll> max_dp(n + 1); // maximum sum only using 0..i
        vector<ll> used_max_dp(
            n + 1); // maximum sum only using 0..i and using i mandatory
        ll sum = 0;
        for (int i = 0; i < n; i++) {
            cin >> v[i];
            sum += v[i];
        }
        max_dp[0] = used_max_dp[0] = 0;
        for (int i = 0; i < n; i++) {
            used_max_dp[i + 1] = max(used_max_dp[i], 0LL) + v[i];
            max_dp[i + 1] = max(max_dp[i], used_max_dp[i + 1]);
        }
        sum = (sum % MOD + MOD) % MOD; 
        ll largest_subarray = max_dp[n] % MOD; // this is the largest sum.
        ll power = get_power_of_2(k);
        power = (power + MOD - 1) % MOD;
        cout << ((sum + (power * largest_subarray) % MOD) % MOD) << "\n";
    }
}