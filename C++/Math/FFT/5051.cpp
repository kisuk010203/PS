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

    ll n;
    cin >> n;
    vector<ll> diagonal(n); // n-1 degree
    vector<ll> square(n);   // n-1 degree

    fill(diagonal.begin(), diagonal.end(), 0);
    fill(square.begin(), square.end(), 0);

    for (ll i = 1; i < n; i++) {
        ll temp = (i * i) % n;
        square[temp]++;
        diagonal[(temp * 2) % n]++;
    }

    vector<ll> ans = mul_poly(square, square); // 2n-2 degree (0~2n-2)
    ll cnt = 0;
    for (ll i = 1; i < n; i++) {
        ll idx = (i * i) % n;
        if (idx == n - 1) {
            cnt += (ans[n - 1] - diagonal[n - 1]) / 2 + diagonal[n - 1];
        } else
            cnt +=
                (ans[idx] + ans[idx + n] - diagonal[idx]) / 2 + diagonal[idx];
    }

    cout << cnt << endl;
}
