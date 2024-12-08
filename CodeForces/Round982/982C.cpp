#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define all(v) v.begin(), v.end()
#define rep(i, a, b) for(int i = a; i < b; i++)
#define repd(i, a, b) for(int i = a; i >= b; i--)
#define each(a, b) for(auto& a : b)
typedef pair<ll, ll> pll;

int main() {
    cin.tie(NULL); ios_base::sync_with_stdio(false);
    ll T; cin >> T;
    while(T--) {
        ll n; cin >> n;
        vector<ll> v(n) ;
        vector<pll> target(n);
        map<ll, ll> max_map;
        rep(i, 0, n) cin >> v[i];
        rep(i, 0, n) target[i] = {i + v[i], i}; // need cnt, inc
        sort(all(target));
        ll cnt = n;
        max_map[target[n-1].first] = target[n-1].first + target[n-1].second;
        repd(i, n - 2, 0) {
            // each(x, max_map) cout << x.first << " : " << x.second << ' ';
            // cout << '\n';
            ll nxt = target[i].first + target[i].second;
            if(max_map.find(nxt) == max_map.end()) {
                if(max_map.find(target[i].first) == max_map.end())
                    max_map[target[i].first] = nxt;
                else
                    max_map[target[i].first] = max(max_map[target[i].first], nxt); 
            }
            else {
                if(max_map.find(target[i].first) == max_map.end())
                    max_map[target[i].first] = max_map[nxt];
                else
                    max_map[target[i].first] = max(max_map[target[i].first], max_map[nxt]);
            }
        }
        if(max_map.find(n) != max_map.end()) cnt = max_map[n];
        cout << cnt << '\n';

    }
}