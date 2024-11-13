#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t; cin >> t;
    while (t--){
        ll n, k; cin >> n >> k;
        vector<ll> v(n);
        for (int i = 0; i < n; i++){
            cin >>v[i];
        }
        sort(v.begin(), v.end());
        ll ans = 0;
        ll cnt = 0;
        ll each = 0;
        for(int i = 0; i < n; i++) {
            if(v[i] > each) {
                if((v[i] - each) * (n - i) >= k - cnt) {
                    ans += (k - cnt);
                    break;
                } else {
                    ans += (v[i] - each) * (n - i);
                    cnt += (v[i] - each) * (n - i);
                    each = v[i];
                    ans++;
                }
            } else ans++;
        }
        cout << ans << "\n";
        
    }
    
}