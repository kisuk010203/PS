#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main() {
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(false);
    int n;
    cin >> n;
    vector<int> contestants(n);
    for (int i = 0; i < n; i++) {
        cin >> contestants[i];
    }
    int super, co_super;
    cin >> super >> co_super;
    ll ans = 0;
    for (int i = 0; i < n; i++) {
        ans++;
        contestants[i] -= super;
        if (contestants[i] > 0)
            ans += (contestants[i] + co_super - 1) / co_super;
    }
    cout << ans << "\n";
}
