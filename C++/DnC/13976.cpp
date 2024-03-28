#include <bits/stdc++.h>
using namespace std;
#define MOD (int)(1e9 + 7)
typedef long long ll;
typedef pair<ll, ll> p;
typedef pair<p, p> matrix;
matrix mul(matrix a, matrix b) {
    ll aa = (2 * MOD + a.first.first * b.first.first % MOD +
             a.first.second * b.second.first % MOD) %
            MOD;
    ll ab = (2 * MOD + a.first.first * b.first.second % MOD +
             a.first.second * b.second.second % MOD) %
            MOD;
    ll ba = (2 * MOD + a.second.first * b.first.first % MOD +
             a.second.second * b.second.first % MOD) %
            MOD;
    ll bb = (2 * MOD + a.second.first * b.first.second % MOD +
             a.second.second * b.second.second % MOD) %
            MOD;
    return make_pair(make_pair(aa, ab), make_pair(ba, bb));
}
matrix exp(ll n) {
    if (n == 0)
        return make_pair(make_pair(1, 0), make_pair(0, 1));
    if (n == 1)
        return make_pair(make_pair(4, -1), make_pair(1, 0));
    matrix temp = exp(n / 2);
    if (n % 2 == 0)
        return mul(temp, temp);
    return mul(mul(temp, temp), make_pair(make_pair(4, -1), make_pair(1, 0)));
}
int main() {
    ll n;
    cin >> n;
    if (n % 2) {
        cout << 0;
        return 0;
    }
    matrix ret = exp(n / 2 - 1);
    ll ans =
        (MOD + ((MOD + ret.first.first) * 3) % MOD + ret.first.second) % MOD;
    cout << ans;
}
