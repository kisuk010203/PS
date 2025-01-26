#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main() {
    cin.tie(NULL); ios_base::sync_with_stdio(false);
    int T; cin >> T;
    while(T--) {
        int n; cin >> n;
        vector<ll> a(n);
        for(auto& x : a) cin >> x;

        vector<ll> suff_min(n);
        suff_min[n - 1] = a[n - 1];
        for(int i = n - 2; i >= 0; i--) {
            suff_min[i] = min(suff_min[i + 1], a[i]);
        }
        vector<ll> ans;
        vector<ll> backs;
        ll min_backs = 2e9;

        for(int i = 0; i < n; i++) {
            if(a[i] > suff_min[i]){ 
                backs.push_back(a[i] + 1);
                min_backs = min(min_backs, a[i] + 1);
            }
            else if(a[i] <= min_backs) {
                ans.push_back(a[i]);
            } else {
                for(int j = i; j < n; j++)
                    backs.push_back(a[j] + 1);
                break;
            }
        }

        sort(backs.begin(), backs.end());
        for(auto &x : ans) cout << x << ' ';
        for(auto &x : backs) cout << x << ' ';
        cout << '\n';

    }
}