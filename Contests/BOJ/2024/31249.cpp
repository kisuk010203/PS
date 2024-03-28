#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main() {
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(false);
    int T;
    cin >> T;
    while (T--) {
        ll n, m;
        cin >> n >> m;
        if (n < m)
            swap(n, m);
        if (n == m) {
            cout << n << " " << 3 << "\n";
            continue;
        }
        if (n <= 2 * m) {
            cout << m << " " << 7 << "\n";
            continue;
        } else if (n <= 2 * m + 2) {
            ll ret = 3 + 2 * (n - m - 1);
            ll ret1 = min(ret, 7LL);
            cout << m + 1 << " " << ret1 << "\n";
        } else {
            cout << m + 1 << " " << 7 + 2 * (n - 2 * m - 2) << "\n";
        }
    }
}