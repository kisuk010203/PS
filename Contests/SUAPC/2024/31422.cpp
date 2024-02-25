#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define MOD 998244353
int main() {
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(false);
    ll N;
    cin >> N;
    vector<ll> v(N);
    for (ll i = 0; i < N; i++) {
        cin >> v[i];
    }
    ll and_result = 0, or_result = 0, xor_result = 0;
    for (ll i = 0; i < 30; i++) {
        vector<ll> zero_blocks;
        vector<ll> one_blocks;
        vector<ll> cumul_sum{0};
        ll prev = -1;
        ll zero_cnt = 0;
        ll one_cnt = 0;

        for (ll j = 0; j < N; j++) {
            int curr_bit = (v[j] >> i) & 1;
            if (curr_bit == 0) {
                zero_cnt++;
                if (prev == 1) {
                    one_blocks.push_back(one_cnt);
                    one_cnt = 0;
                }
            } else {
                one_cnt++;
                if (prev == 0) {
                    zero_blocks.push_back(zero_cnt);
                    zero_cnt = 0;
                }
            }
            prev = curr_bit;
            cumul_sum.push_back(cumul_sum.back() ^ curr_bit);
        }
        if (prev == 0) {
            zero_blocks.push_back(zero_cnt);
        } else {
            one_blocks.push_back(one_cnt);
        }

        ll curr_and_res = 0, curr_or_res = (N * (N + 1) / 2) % MOD,
           curr_xor_res = 0;
        for (auto one : one_blocks) {
            curr_and_res += (one * (one + 1) / 2) % MOD;
            curr_and_res %= MOD;
        }
        for (auto zero : zero_blocks) {
            curr_or_res += MOD;
            curr_or_res -= ((zero * (zero + 1) / 2) % MOD);
            curr_or_res %= MOD;
        }
        ll odd_count = 0;
        for (auto cum : cumul_sum) {
            if (cum == 1)
                odd_count++;
        }
        curr_xor_res = (odd_count * (N + 1 - odd_count) % MOD);
        and_result = (and_result + (curr_and_res * ((1 << i) % MOD)) % MOD) % MOD;
        or_result = (or_result + (curr_or_res * ((1 << i) % MOD)) % MOD) % MOD;
        xor_result = (xor_result + (curr_xor_res * ((1 << i) % MOD)) % MOD) % MOD;
    }
    cout << and_result << " " << or_result << " " << xor_result << '\n';
}