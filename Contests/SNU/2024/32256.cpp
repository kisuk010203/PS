#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll sub_dp(ll k, ll coeff1, ll coeff2) { // coeff1 k coeff k - 1
    if (k <= 6) {
        return coeff1 * ((k + 1) / 2 - 1) + coeff2 * (k / 2 - 1);
    }
    if (k % 2 == 0) {
        return sub_dp(k / 2 + 1, coeff1, coeff1 + 2 * coeff2);
    }
    return sub_dp(k / 2 + 1, coeff1 * 2 + coeff2, coeff2);
}
ll dp(ll n) { return sub_dp(n, 1, 0); }
int main() {
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    int T;
    cin >> T;
    while (T--) {
        ll n;
        cin >> n;
        if (n <= 5) {
            cout << (n + 1) / 2 << "\n";
            continue;
        }

        ll temp = n, cnt = 0;
        while (temp) {
            cnt++;
            temp >>= 1;
        }
        cnt--;
        // (1<<cnt)+1, n-(1<<cnt)  + 1
        ll ans = (1L << (cnt - 1)) + dp(n - (1L << cnt)) + 1L;
        cout << ans << "\n";
    }
}