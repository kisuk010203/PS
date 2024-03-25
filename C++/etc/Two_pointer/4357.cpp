#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> pll;
ll get_power(ll base, ll prime, ll expo) {
    if (expo == 0)
        return 1;
    ll temp = get_power(base, prime, expo / 2);
    if (expo % 2 == 0)
        return (temp * temp) % prime;
    return ((temp * temp) % prime) * base % prime;
}
ll get_inverse(ll base, ll prime) {
    return get_power(base, prime, prime - 2);
}

int main() {
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(false);
    ll p, n, b;
    while (cin >> p >> b >> n) {
        ll MOD = (ll)sqrt(p - 1);
        ll inverse_b = get_inverse(b, p);
        ll giant_b = get_power(b, p, MOD);
        ll baby_step = MOD;
        ll giant_step = p / MOD;

        unordered_map<ll, ll> babies, giants;
        ll curr = n;
        babies[n] = 0;
        for (int i = 1; i < baby_step; i++) {
            curr = (curr * inverse_b) % p;
            if (curr == n)
                break;
            babies[curr] = i;
        }

        curr = 1;
        giants[0] = 1;
        for (int i = 1; i < giant_step; i++) {
            curr = (curr * giant_b) % p;
            if (curr == 1)
                break;
            giants[i] = curr;
        }

        bool break_flag = false;
        for (int giant = 0; giant < giant_step; giant++) {
            ll curr = giants[giant];
            if (babies.find(curr) != babies.end()) {
                ll ans = giant * baby_step + babies[curr];
                cout << ans << "\n";
                break_flag = true;
                break;
            }
        }

        if (break_flag)
            continue;
        cout << "no solution\n";
    }
}
