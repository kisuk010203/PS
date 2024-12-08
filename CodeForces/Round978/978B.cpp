#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define all(v) v.begin(), v.end()
#define rep(i, a, b) for(int i = a; i < b; i++)
#define each(a, b) for(auto& a : b)
typedef pair<ll, ll> pll;

int main() {
    cin.tie(NULL); ios_base::sync_with_stdio(false);
    int T; cin >> T;
    while(T--) {
        ll n, x; cin >> n >> x;
        vector<ll> v(n);
        rep(i, 0, n) cin >> v[i];
        ll cust = 0;
        ll su = 0L;
        ll  ma = 0L;
        each(x, v) {su += x; ma = max(ma, x);}
        ll ans = max(ma, (su + x - 1) / x);
        cout << ans << "\n";
    }
}