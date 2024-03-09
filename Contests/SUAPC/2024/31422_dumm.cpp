#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define MOD 998244353
int main() {
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(false);
    ll n;
    cin >> n;
    vector<ll> v(n);
    for (ll i = 0; i < n; i++) {
        cin >> v[i];
    }
    ll and_result = 0, or_result = 0, xor_result = 0;
    for (int i = 0; i < n; i++) {
        for (int j = i; j < n; j++) {
            ll curr_and_result = -1, curr_or_result = 0, curr_xor_result = 0;
            for (int k = i; k <= j; k++) {
                curr_and_result &= v[k];
                curr_or_result |= v[k];
                curr_xor_result ^= v[k];
            }
            and_result = (and_result + curr_and_result % MOD) % MOD;
            or_result = (or_result + curr_or_result % MOD) % MOD;
            xor_result = (xor_result + curr_xor_result % MOD) % MOD;
        }
    }
    cout << and_result << " " << or_result << " " << xor_result << '\n';
}