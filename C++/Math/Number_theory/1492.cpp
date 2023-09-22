#include <bits/stdc++.h>
using namespace std;
#define PRIME 1000000007
typedef long long ll;
ll combination[53][53];
ll exp_sum[51];
ll exp(ll base, ll exponent) {
    if (exponent == 0)
        return 1;
    ll sqrt = exp(base, exponent / 2);
    ll temp = (sqrt * sqrt) % PRIME;
    if (exponent % 2 == 1) {
        return (temp * base) % PRIME;
    }
    return temp;
}
ll inverse(ll num) { return exp(num, PRIME - 2); }
void set_combination(int n) {
    for (int i = 0; i <= n; i++) {
        combination[i][0] = combination[i][i] = 1;
    }
    for (int i = 2; i <= n; i++) {
        for (int j = 1; j <= i; j++) {
            combination[i][j] =
                (combination[i - 1][j - 1] + combination[i - 1][j]) % PRIME;
        }
    }
}
void set_exp_sum(ll n, ll k) {
    if (k == 0) {
        exp_sum[0] = n;
        return;
    }
    ll temp = 1;
    for (int i = 0; i < k; i++) {
        temp = (temp + exp_sum[i] * combination[k + 1][i]) % PRIME;
    }
    temp = (exp(n + 1, k + 1) - temp + PRIME) % PRIME;
    temp = (temp * inverse(k + 1)) % PRIME;
    exp_sum[k] = temp;
}
int main(int argc, char const *argv[]) {
    ll n, k;
    cin >> n >> k;
    memset(exp_sum, 0, sizeof(exp_sum));
    memset(combination, 0, sizeof(combination));

    set_combination(k + 2);
    for (int i = 0; i <= k; i++) {
        set_exp_sum(n, i);
    }
    cout << exp_sum[k] << "\n";
    return 0;
}
