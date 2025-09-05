#include <bits/stdc++.h>
using namespace std;
using ull = unsigned long long;
using u128 = __uint128_t;

ull mulmod(ull a, ull b, ull m) {
    return (ull)((u128)a * b % m);
}
ull powmod(ull a, ull d, ull m) {
    ull r = 1;
    while (d) {
        if (d & 1) r = mulmod(r, a, m);
        a = mulmod(a, a, m);
        d >>= 1;
    }
    return r;
}
bool isPrime(ull n) {
    if (n < 2) return false;
    for (ull p: {2ULL,3ULL,5ULL,7ULL,11ULL,13ULL,17ULL,19ULL,23ULL,29ULL,31ULL,37ULL})
        if (n%p==0) return n==p;
    ull d = n-1, s = 0;
    while ((d & 1) == 0) { d >>= 1; ++s; }
    // deterministic bases for 64-bit
    ull bases[] = {2ULL, 325ULL, 9375ULL, 28178ULL, 450775ULL, 9780504ULL, 1795265022ULL};
    for (ull a: bases) {
        if (a % n == 0) continue;
        ull x = powmod(a, d, n);
        if (x == 1 || x == n-1) continue;
        bool comp = true;
        for (ull r = 1; r < s; ++r) {
            x = mulmod(x, x, n);
            if (x == n-1) { comp = false; break; }
        }
        if (comp) return false;
    }
    return true;
}
mt19937_64 rng(chrono::high_resolution_clock::now().time_since_epoch().count());
ull pollard(ull n) {
    if (n % 2ULL == 0ULL) return 2ULL;
    if (n % 3ULL == 0ULL) return 3ULL;
    ull c = uniform_int_distribution<ull>(1, n-1)(rng);
    ull x = uniform_int_distribution<ull>(0, n-1)(rng);
    ull y = x;
    ull d = 1;
    auto f = [&](ull v){ return (mulmod(v, v, n) + c) % n; };
    while (d == 1) {
        x = f(x);
        y = f(f(y));
        d = std::gcd<ull>(x > y ? x - y : y - x, n);
        if (d == n) return pollard(n);
    }
    return d;
}
void factor_rec(ull n, vector<ull>& fac) {
    if (n == 1) return;
    if (isPrime(n)) { fac.push_back(n); return; }
    ull d = pollard(n);
    factor_rec(d, fac);
    factor_rec(n / d, fac);
}
bool isPerfectSquare(ull n) {
    ull r = (ull)floor(sqrt((long double)n));
    while ((u128)r * r < n) ++r;
    while ((u128)r * r > n) --r;
    return (u128)r * r == n;
}
bool isSumOfTwoSquares(ull n) {
    vector<ull> fac;
    factor_rec(n, fac);
    sort(fac.begin(), fac.end());
    for (size_t i = 0; i < fac.size();) {
        ull p = fac[i];
        size_t j = i;
        while (j < fac.size() && fac[j] == p) ++j;
        size_t cnt = j - i;
        if (p % 4ULL == 3ULL && (cnt & 1ULL)) return false;
        i = j;
    }
    return true;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ull n; 
    if (!(cin >> n)) return 0;
    if (isPerfectSquare(n)) { cout << 1 << '\n'; return 0; }
    if (isSumOfTwoSquares(n)) { cout << 2 << '\n'; return 0; }
    ull m = n;
    while (m % 4ULL == 0ULL) m /= 4ULL;
    if (m % 8ULL == 7ULL) cout << 4 << '\n'; 
    else cout << 3 << '\n';
    return 0;
}
