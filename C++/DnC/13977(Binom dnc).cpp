#include <iostream>
#include <vector>
using namespace std;
typedef long long ll;
#define MOD 1000000007
vector<int> fact(4000001);
ll getpow(ll base, ll power) {
    if (!power)
        return 1;
    ll temp = getpow(base, power / 2);
    if (power % 2)
        return ((temp * temp) % MOD * base) % MOD;
    return (temp * temp) % MOD;
}
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    fact[0] = 1;
    for (int i = 1; i < 4000001; i++)
        fact[i] = (ll)fact[i - 1] * i % MOD;
    int t;
    cin >> t;
    for (int i = 0; i < t; i++) {
        int n, k;
        cin >> n >> k;
        ll facn = fact[n], fack = fact[k], facr = fact[n - k];
        fack = getpow(fack, MOD - 2);
        facr = getpow(facr, MOD - 2);
        cout << ((facn * fack) % MOD) * facr % MOD << '\n';
    }
}
