#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define MOD 1000000007
int main() {
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(false);
    int T;
    cin >> T;
    vector<bool> is_prime(1000001, true);
    is_prime[0] = is_prime[1] = false;
    for (int i = 2; i * i <= 1000000; i++) {
        if (is_prime[i]) {
            for (int j = i * i; j <= 1000000; j += i) {
                is_prime[j] = false;
            }
        }
    }
    while (T--) {
        int n;
        cin >> n;
        ll ans = 0;
        for (int i = 2; i <= n; i++) {
            if (!is_prime[i]) {
                continue;
            } else { // prime
                ll whole = (n + 1) / i - 1;
                ll rem = (n + 1) % i;
                rem = ((i - ((whole + 1) % i)) * rem) % MOD;
                ll whole_whole = whole / i;
                ll whole_rem = whole % i;
                whole_whole =
                    (whole_whole * ((i * i * (i - 1) / 2) % MOD)) % MOD;
                whole_rem =
                    (i * (i * whole_rem - whole_rem * (whole_rem + 1) / 2)) %
                    MOD;
                // cout << "i : " << i << " " << whole_whole  << " " <<  whole_rem << " " <<  rem
                //      << "\n";
                ans = (ans + whole_whole + whole_rem + rem) % MOD;
            }
        }
        if(n >= 4) {
            ll quo = (n >> 3) << 3;
            ll rem = n & 7;
            rem = max(0LL, rem - 3);
            ans = (ans + quo + rem * 2) % MOD;
        }
        cout << ans << "\n";
    }
}