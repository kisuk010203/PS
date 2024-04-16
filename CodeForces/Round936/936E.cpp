#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define MAX 200005
#define MOD 1000000007
ll dp[MAX];
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
ll get_inverse(ll a) {
    if (dp[a] != 0)
        return dp[a];
    return dp[a] = get_power(a, MOD - 2);
}
ll get_comb(ll n, ll r) {
    if (r > (n >> 1))
        r = n - r;
    ll res = 1;
    for (ll i = 0; i < r; i++) {
        res = (res * (n - i) % MOD) * get_inverse(i + 1) % MOD;
    }
    return res;
}

int main() {
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(false);
    int T;
    cin >> T;
    memset(dp, 0, sizeof(dp));
    while (T--) {
        int n, m1, m2;
        cin >> n >> m1 >> m2;
        vector<ll> prefix_max(m1);
        vector<ll> suffix_max(m2);
        for (int i = 0; i < m1; i++) {
            cin >> prefix_max[i];
        }
        for (int i = 0; i < m2; i++) {
            cin >> suffix_max[i];
        }
        if (suffix_max[0] != prefix_max[m1 - 1] || suffix_max[m2 - 1] != n ||
            prefix_max[0] != 1) {
            cout << "0\n";
            continue;
        }
        ll ans = get_comb(n - 1, suffix_max[0] - 1);
        ll left_pointer = suffix_max[0] - 1, right_pointer = suffix_max[0] + 1;
        ll v_left_pointer = m1 - 2, v_right_pointer = 1;
        while (left_pointer > 1) {
            if (v_left_pointer >= 0 &&
                prefix_max[v_left_pointer] == left_pointer) {
                v_left_pointer--;
            } else {
                ans = (ans * (left_pointer - 1)) % MOD;
            }
            left_pointer--;
        }
        while (right_pointer < n) {
            if (v_right_pointer < m2 &&
                suffix_max[v_right_pointer] == right_pointer) {
                v_right_pointer++;
            } else {
                ans = (ans * (n - right_pointer)) % MOD;
            }
            right_pointer++;
        }

        cout << ans << "\n";
    }
}