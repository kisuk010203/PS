#include <bits/stdc++.h>
using namespace std;
#define MOD 1000000007
typedef long long ll;
ll hanoi[1000000];
ll original_hanoi(ll n) {
    if (n == 0)
        return 1;
    ll temp = original_hanoi(n / 2);
    if (n % 2 == 0)
        return (temp * temp) % MOD;
    return ((temp * temp) % MOD * 2) % MOD;
}
ll res(ll n, ll k) {
    if (n < 0)
        return 0;
    if (hanoi[n] == k)
        return res(n - 1, k);
    ll new_k = 6 - (hanoi[n] + k);
    return (original_hanoi(n) + res(n - 1, new_k)) % MOD;
}
int main() {
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(false);
    ll n, k;
    cin >> n >> k;
    for (ll i = 0; i < n; i++) {
        cin >> hanoi[i];
    }
    cout << res(n - 1, k);
}
