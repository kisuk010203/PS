#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define all(v) v.begin(), v.end()
#define rep(i, a, b) for(ll i = a; i < b; i++)
#define drep(i, a, b) for(ll i = a; i >= b; i--)
#define each(a, b) for(auto& a : b)
typedef pair<ll, ll> pll;
 
int main() {
    cin.tie(NULL); ios_base::sync_with_stdio(false);
    ll T; cin >> T;
    while(T--) {
        ll n; cin >> n;
        vector<ll> v(n);
        rep(i, 0, n) cin >> v[i];
        ll ans = ((n + 1) * n) / 2;
        rep(i, 1, 10) {
            vector<ll> new_v(n);
            vector<ll> acc(n + 1);
            unordered_map<ll, ll> umap;
 
            rep(j, 0, n) new_v[j] = (v[j] <= i) ? -1 : 1;
            acc[0] = 0;
            rep(j, 0, n) acc[j + 1] = acc[j] + new_v[j];
 
            ll cur = 0;
            ll lft = 0;
 
            rep(j, 0, n) {
                if(v[j] == i) {
                    while(lft <= j) {
                        if(umap.find(acc[lft]) == umap.end()) umap[acc[lft]] = 1;
                        else umap[acc[lft]]++;
                        lft++;
                    }
                    
                }
                if(umap.find(acc[j + 1]) != umap.end())
                    ans -= umap[acc[j + 1]];
                
            }
            // cout << i << ": " << ans << "\n";
        }
        cout << ans << "\n";
    }
}