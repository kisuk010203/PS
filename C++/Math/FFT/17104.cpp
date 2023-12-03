#include <bits/stdc++.h>
using namespace std;
const double PI = M_PI;
#define MAX 1000000
typedef long long ll;
typedef complex<double> cpx;
void FFT(vector<cpx> &v, bool inv) {
    ll n = v.size();
    for (int i = 1, j = 0; i < n; i++) {
        ll bit = n >> 1;
        while (j >= bit) {
            j -= bit;
            bit >>= 1;
        }
        j += bit;
        if (i < j)
            swap(v[i], v[j]);
    }

    for (int k = 1; k < n; k <<= 1) {
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

vector<ll> mul_poly(vector<ll> &p, vector<ll> &q) {
    vector<cpx> p_cpx(p.begin(), p.end());
    vector<cpx> q_cpx(q.begin(), q.end());

    ll n = 2;
    while (n < p.size() + q.size()) {
        n <<= 1;
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
    return ans;
}

int main() {
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(false);

    vector<ll> is_prime(MAX);
    vector<ll> odd_primes(MAX / 2);

    fill(is_prime.begin(), is_prime.end(), 1);

    is_prime[0] = is_prime[1] = 0;
    for (int i = 2; i < MAX; i++) {
        if (is_prime[i]) {
            for (int j = 2 * i; j < MAX; j += i)
                is_prime[j] = 0;
        }
    }

    for (int i = 0; i < MAX / 2; i++) {
        odd_primes[i] = is_prime[2 * i + 1];
    }

    vector<ll> ans = mul_poly(odd_primes, odd_primes);

    ll T;
    cin >> T;
    while (T--) {
        ll N;
        cin >> N;
        if (N == 4)
            cout << "1\n";
        else {
            cout << (ans[(N - 2) / 2] + 1) / 2 << "\n";
        }
    }
}
