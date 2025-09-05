#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll gcd(ll a, ll b) {
    while (b != 0) {
        ll temp = a % b;
        a = b;
        b = temp;
    }
    return a;
}

ll mod_exp(ll base, ll exp, ll mod) {
    ll result = 1;
    base = base % mod;
    while (exp > 0) {
        if (exp & 1) result = (result * base) % mod;
        exp = exp >> 1;
        base = (base * base) % mod;
    }
    return result;
}

bool miller_rabin(ll n, int prime) {
    if (n % prime == 0)
        return true;
    ll cnt = 0, d = n - 1;
    while ((d & 1) == 0) {
        d >>= 1;
        cnt++;
    }

    ll x = mod_exp(prime, d, n);
    if (x == 1 || x == n - 1)
        return true;
    for (int i = 0; i < cnt - 1; i++) {
        x = (x * x) % n;
        if (x == n - 1)
            return true;
    }
    return false;
}

bool is_prime(int n) {
    vector<ll> test_bases = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41};
    for (auto base : test_bases) {
        if (base == n) {
            return true;
        }
        if (!miller_rabin(n, base)) {
            return false;
        }
    }
    return true;
}

void pollard_rho(ll n, vector<ll> &factors) {
    if (n == 1) return;
    if (n % 2 == 0) {
        factors.push_back(2);
        pollard_rho(n / 2, factors);
        return;
    }
    if (is_prime(n)) {
        factors.push_back(n);
        return;
    }
    ll x = rand() % (n - 2) + 2;
    ll y = x;
    ll c = rand() % (n - 1) + 1;
    ll d = 1;
    while (d == 1) {
        x = (mod_exp(x, 2, n) + c + n) % n;
        y = (mod_exp(y, 2, n) + c + n) % n;
        y = (mod_exp(y, 2, n) + c + n) % n;
        d = gcd(abs(x - y), n);
        if (d == n) {
            pollard_rho(n, factors);
            return;
        }
    }
    pollard_rho(d, factors);
    pollard_rho(n / d, factors);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    ll n; cin >> n;
    vector<ll> factors;
    pollard_rho(n, factors);
    sort(factors.begin(), factors.end());
    for (int i = 0; i < factors.size(); i++) {
        cout << factors[i];
        if (i != factors.size() - 1) cout << " ";
    } cout << "\n";
    return 0;
}
