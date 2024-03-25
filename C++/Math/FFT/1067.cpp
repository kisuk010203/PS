#include <bits/stdc++.h>
using namespace std;
const double PI = M_PI;
#define MAX 60000
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
    ll n;
    cin >> n;
    vector<ll> p(n);
    vector<ll> q(n);
    for (int i = 0; i < n; i++) {
        ll temp;
        cin >> temp;
        p[i] = temp;
    }
    for (int i = 0; i < n; i++) {
        ll temp;
        cin >> temp;
        q[n - 1 - i] = temp;
    }
    vector<ll> target = mul_poly(p, q);
    ll ans_max = target[n - 1];
    for (int i = 0; i < n - 1; i++) {
        ans_max = max(ans_max, target[i] + target[n + i]);
    }
    cout << ans_max << endl;
}
