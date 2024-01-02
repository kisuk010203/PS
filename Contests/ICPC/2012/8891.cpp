#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> pll;
vector<ll> combination(201);
pll decrypt(ll n) {
    ll idx = lower_bound(combination.begin(), combination.end(), n) -
             combination.begin();
    ll diff = idx * (idx - 1) / 2 - n;
    return {idx - 1 - diff, diff + 1};
}
ll encrypt(pll a) {
    ll x = a.first, y = a.second;
    ll largest = (x + y) * (x + y - 1) / 2;
    return largest - (y - 1);
}
int main() {
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(false);
    ll sum = 0;
    for (ll i = 1; i < 200; i++) {
        sum += i;
        combination[i + 1] = sum;
    }
    ll T;
    cin >> T;
    while (T--) {
        ll a, b;
        cin >> a >> b;
        pll aa = decrypt(a);
        pll bb = decrypt(b);
        pll sum = {aa.first + bb.first, aa.second + bb.second};
        cout << encrypt(sum) << "\n";
    }
}
