#include <bits/stdc++.h>
using namespace std;
int main() {
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(false);
    int t;
    cin >> t;
    while (t--) {
        int k, q;
        cin >> k >> q;
        vector<int> a(k);
        for (int i = 0; i < k; i++) {
            cin >> a[i];
        }
        while (q--) {
            int n;
            cin >> n;
            int ans = n;
            for (int i = k - 1; i >= 0; i--) {
                if (ans < a[i])
                    continue;
                ans -= (i + 1) * ((ans - a[i]) / (i + 1) + 1);
            }
            cout << ans << " ";
        }
        cout << "\n";
    }
}