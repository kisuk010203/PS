#include <bits/stdc++.h>
using namespace std;
const double PI = M_PI;
#define MAX 1000000
typedef long long ll;
typedef complex<double> cpx;
void FFT(vector<cpx>& v, bool inv) {
    ll n = v.size();
    for (int i = 1, j = 0; i < n; i++) {
        ll bit = n / 2;
        while (j >= bit) {
            j -= bit;
            bit /= 2;
        }
        j += bit;
        if (i < j)
            swap(v[i], v[j]);
    }

    for (int k = 1; k < n; k *= 2) {
        double angle = inv ? PI / k : -PI / k;
        cpx w(cos(angle), sin(angle));

        for (int i = 0; i < n; i += k * 2) {
            cpx z(1, 0);

            for (int j = 0; j < k; j++) {
                cpx even = v[i + j];
                cpx odd = v[i + j + k];

                v[i + j] = even + z * odd;
                v[i + j + k] = even - z * odd;

                z *= w;
            }
        }
    }

    if (inv)
        for (int i = 0; i < n; i++) {
            v[i] /= n;
        }
}

vector<ll> mul_poly(vector<ll>& p, vector<ll>& q) {
    vector<cpx> p_cpx(p.begin(), p.end());
    vector<cpx> q_cpx(q.begin(), q.end());

    ll n = 2;
    while (n < p.size() + q.size()) {
        n *= 2;
    }
    p_cpx.resize(n);
    FFT(p_cpx, 0);
    q_cpx.resize(n);
    FFT(q_cpx, 0);

    for (int i = 0; i < n; i++) {
        p_cpx[i] *= q_cpx[i];
    }
    FFT(p_cpx, 1);

    vector<ll> ans(n);
    for (int i = 0; i < n; i++) {
        ans[i] = round(p_cpx[i].real());
    }
    ans.resize(p.size() + q.size() - 1);
    return ans;
}

int main() {
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(false);
    vector<bool> is_prime(MAX);
    for (int i = 0; i < MAX; i++) {
        is_prime[i] = true;
    }
    is_prime[0] = is_prime[1] = false;
    for (int i = 2; i < MAX; i++) {
        if (is_prime[i]) {
            for (int j = 2 * i; j < MAX; j += i)
                is_prime[j] = false;
        }
    }
    vector<ll> prime_poly(MAX);
    vector<ll> semi_prime_poly(MAX);

    for (int i = 0; i < MAX; i++) {
        if (i % 2 == 1) {
            prime_poly[i] = (ll)(is_prime[i]);
            semi_prime_poly[i] = 0;
        } else {
            prime_poly[i] = 0;
            semi_prime_poly[i] = (ll)is_prime[i / 2];
        }
    }

    vector<ll> ans = mul_poly(prime_poly, semi_prime_poly);

    ll T;
    cin >> T;
    while (T--) {
        ll N;
        cin >> N;
        cout << ans[N] << endl;
    }
}
