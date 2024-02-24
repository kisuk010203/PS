#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define MOD 998244353
int main() {
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(false);
    ll width, height, k, time;
    cin >> width >> height >> k >> time;
    ll ans = 1;
    while (k--) {
        ll x, y;
        cin >> x >> y;
        ll poss_width = 1 + min(x - 1, time) + min(width - x, time);
        ll poss_height = 1 + min(y - 1, time) + min(height - y, time);
        ans = (ans * (poss_width * poss_height % MOD)) % MOD;
    }
    cout << ans << '\n';
}