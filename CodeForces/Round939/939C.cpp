#include <bits/stdc++.h>
using namespace std;
int main() {
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(false);
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int ans = 0;
        for (int i = n; i >= 1; i--) {
            ans += i * (2 * i - 1);
        }
        cout << ans << " " << 2 * n << "\n";
        for (int i = n; i >= 1; i--) {
            cout << 1 << " " << i << " ";
            for (int j = 1; j <= n; j++)
                cout << j << " ";
            cout << "\n";
            cout << 2 << " " << i << " ";
            for (int j = 1; j <= n; j++)
                cout << j << " ";
            cout << "\n";
        }
    }
}