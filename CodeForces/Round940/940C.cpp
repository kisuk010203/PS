#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define MOD 1000000007
ll get_power(ll base, ll exp) {
    ll res = 1;
    while (exp > 0) {
        if (exp & 1) {
            res = (res * base) % MOD;
        }
        base = (base * base) % MOD;
        exp >>= 1;
    }
    return res;
}
ll get_inverse(ll a) { return get_power(a, MOD - 2); }
int main() {
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(false);
    int T;
    cin >> T;
    while (T--) {
        ll n, k;
        cin >> n >> k;
        for (int i = 0; i < k; i++) {
            int a, b;
            cin >> a >> b;
            if (a == b)
                n--;
            else
                n -= 2;
        }
        ll ans = 1;
        ll accum = 1;
        for (int i = 1; i <= (n >> 1); i++) {

            ll temp = ((n - 2 * i + 1) * (n - 2 * i + 2)) % MOD;
            temp = (temp * get_inverse(i)) % MOD;
            accum = (accum * temp) % MOD;

            ans = (ans + accum) % MOD;
        }
        cout << ans << "\n";
    }
}