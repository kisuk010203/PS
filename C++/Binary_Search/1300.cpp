#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n, k;
ll find_num(ll target) {
    ll sum = 0;
    for (ll i = 1; i <= n; i++) {
        sum += min(n, target / i);
    }
    return sum;
}
int main() {
    cin >> n >> k;
    ll start = 1, end = n * n;
    while (start < end) {
        ll mid = (start + end) / 2;
        ll temp = find_num(mid);
        if (k <= temp)
            end = mid;
        else
            start = mid + 1;
    }
    cout << start;
}
