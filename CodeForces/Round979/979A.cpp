#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> pll;

int main() {
    cin.tie(NULL); ios_base::sync_with_stdio(false);
    int T; cin >> T;
    while(T--) {
        int n; cin >> n;
        vector<ll> v(n);
        for(int i = 0; i < n; i++) cin >> v[i];
        ll min_el  = v[0], max_el = v[0];
        for(auto item : v) {
            min_el = min(min_el, item);
            max_el = max(max_el, item);
        }
        cout << (max_el - min_el) * (n - 1) << "\n";
    }
}