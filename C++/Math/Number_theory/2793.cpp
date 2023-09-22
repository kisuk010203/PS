#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> p;
p arr[4] = {{6, 12},
            {420, 840},
            {8 * 9 * 5 * 7 * 11 * 13, 16 * 9 * 5 * 7 * 11 * 13},
            {(ll)(16 * 27 * 25 * 7 * 11 * 13 * 17) * 19 * 23 * 29 * 31,
             (ll)(16 * 27 * 25 * 7 * 11 * 13 * 17) * 19 * 23 * 29 * 31 * 2}};
ll get_multiples(ll n, ll target) { return n / target; }
ll get_multiples_interval(ll a, ll b, ll target) {
    return get_multiples(b, target) - get_multiples(a - 1, target);
}
ll get_strength_2(ll a, ll b) {
    ll odds = get_multiples_interval(a, b, 1) - get_multiples_interval(a, b, 2);
    return odds;
}
ll get_strength_4(ll a, ll b) {
    ll ret = 0;
    for (p item : arr) {
        ll temp = get_multiples_interval(a, b, item.first) -
                  get_multiples_interval(a, b, item.second);
        ret += temp;
    }
    return ret;
}
ll get_answer(ll a, ll b) {
    ll strength_2 = get_strength_2(a, b);
    ll strength_4 = get_strength_4(a, b);
    ll strength_3 = b - a + 1 - strength_2 - strength_4;
    return strength_2 * 2 + strength_3 * 3 + strength_4 * 4;
}
int main(int argc, char const *argv[]) {

    ll a, b;
    cin >> a >> b;
    cout << get_answer(a, b) << endl;
    return 0;
}
