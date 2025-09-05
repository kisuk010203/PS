#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int mobius[400000];

void compute_mobius() {
    fill(mobius, mobius + 400000, 0);
    mobius[1] = 1;
    for (int i = 1; i < 400000; i++) 
        for (int j = i + i; j < 400000; j += i)
            mobius[j] -= mobius[i];
}

ll compute_square_free(ll n) {
    /**
     * Compute the number of square-free integers up to n
     * using the formula:
     *   sum_{d=1}^{sqrt(n)} mu(d) * floor(n / d^2)
     */
    ll limit = sqrt(n);
    ll result = 0;
    for (ll d = 1; d <= limit; d++) {
        result += mobius[d] * (n / (d * d));
    }
    return result;
}

ll binary_search(ll num) {
    /**
     * Use binary search to find the num'th non-square free number
     */
    ll low = 1, high = num << 2;
    while (low < high) {
        ll mid = (low + high) >> 1;
        ll square_free_count = compute_square_free(mid);
        ll non_square_free_count = mid - square_free_count;
        // printf("mid: %lld, non_sq_f_c: %lld\n", mid, non_square_free_count);
        if (non_square_free_count < num) {
            low = mid + 1;
        } else {
            high = mid;
        }
    }
    return low;
}

int main() {
    ll n; cin >> n;
    compute_mobius();
    cout << binary_search(n) << "\n";
    return 0; 
}