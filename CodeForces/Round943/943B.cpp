#include <bits/stdc++.h>
using namespace std;
int main() {
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(false);
    int T;
    cin >> T;
    while (T--) {
        int n, m;
        cin >> n >> m;
        string a, b;
        cin >> a >> b;
        int ans = 0;
        int b_idx = 0;
        for (int a_idx = 0; b_idx < m && a_idx < n; a_idx++) {
            if (a[a_idx] != b[b_idx]) {
                while (b_idx < m && a[a_idx] != b[b_idx]) {
                    b_idx++;
                }
                if (b_idx == m)
                    break;
            }
            b_idx++;
            ans++;
        }
        cout << ans << "\n";
    }
}