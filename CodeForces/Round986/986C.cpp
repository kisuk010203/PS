#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<long, long> pll;
int main() {
    cin.tie(NULL); ios_base::sync_with_stdio(false);
    int T; cin >> T;
    while(T--) {
        ll n, m, v; cin >> n >> m >> v; 
        vector<ll> tasty(n);
        vector<ll> reversed_tasty(n);
        vector<ll> acc(n + 1, 0LL);
        vector<ll> acc_rev(n + 1, 0LL);
        vector<ll> pref(n + 1, 0LL); // pref[i] = max cnt from 1..i
        vector<ll> suff(n + 1, 0LL); // pref[i] = max cnt from 1..i
        for(int i = 0; i < n; i++) cin >> tasty[i];
        for(int i = 0; i < n; i++) reversed_tasty[i] = tasty[n - i - 1];
        for(int i = 0; i < n; i++) acc[i + 1] = acc[i] + tasty[i]; // acc is sorted
        for(int i = 0; i < n; i++) acc_rev[i + 1] = acc_rev[i] + reversed_tasty[i]; // acc_rev is sorted
        
        for(int i = 1; i < n + 1; i++) {
            if(acc[i] < v) pref[i] = 0LL;
            else{
                int k = upper_bound(acc.begin(), acc.end(), acc[i] - v) - acc.begin();
                pref[i] = 1LL + pref[k - 1];
            }
        }
        for(int i = 1; i < n + 1; i++) {
            if(acc_rev[i] < v) suff[i] = 0LL;
            else {
                int k = upper_bound(acc_rev.begin(), acc_rev.end(), acc_rev[i] - v) - acc_rev.begin();
                suff[i] = 1LL + suff[k - 1];
            }
            
        }
        reverse(suff.begin(), suff.end());
        // for(auto i : pref) cout << i << " ";
        // cout << "\n";
        // for(auto i : suff) cout << i << " ";
        // cout << "\n";
        ll ans = -1LL;
        for(int i = n; i >= 0; i--) { // suffix 
            if(suff[i] >= m) {
                ans = max(ans, acc[i]);
                break;
            }
            int j = lower_bound(pref.begin(), pref.end(), m - suff[i]) - pref.begin();
            // cout << i << " " << j << "\n";
            if(i < j) continue;
            ll res = acc[i] - acc[j];
            ans = max(ans, res);
        }
        cout << ans << "\n";
    }
}