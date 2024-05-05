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
        ll n, k;
        cin >> n >> k;
        if (n == 1) {
            cout << k << "\n";
            continue;
        }
        ll temp = k;
        int power = 0;
        while (temp > 1) {
            temp >>= 1;
            power++;
        }
        ll ans = (1 << power) - 1;
        cout << ans << " " << k - ans << " ";
        for (int i = 2; i < n; i++) {
            cout << "0 ";
        }
        cout << "\n";
    }
}