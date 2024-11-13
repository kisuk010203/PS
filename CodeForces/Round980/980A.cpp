#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t; cin >> t;
    while(t--) {
        ll a, b; cin >> a >> b;
        ll ans = (a >= b) ? a : 2 * a - b;
        ans = (ans > 0) ? ans : 0;
        cout << ans << endl;
    }
}