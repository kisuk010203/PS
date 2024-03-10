#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main() {
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(false);
    ll t;
    cin >> t;
    while (t--) {
        ll n, k;
        cin >> n >> k;
        if(k >= 60) {
            cout << 0 << "\n";
            continue;
        }
        cout << (n >> k) - (n >> (k+1)) << "\n";
    }
}