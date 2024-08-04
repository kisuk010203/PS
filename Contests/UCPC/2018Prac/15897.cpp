#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    ll n;
    cin >> n;
    ll sqrt_n = sqrt(n);
    ll net_sum = 0;
    int i = 1;
    ll quo = 0;
    for (; i <= n; i++) {
        quo = ((n - 1) / i) + 1;
        if (quo > sqrt_n) {
            net_sum += quo;
        } else
            break;
    }
    for (int i = quo; quo >= 2; quo--) {
        ll cnt_quo = ((n - 1) / (quo - 1)) - ((n - 1) / quo);
        net_sum += cnt_quo * quo;
    }
    net_sum++;
    cout << net_sum;
}