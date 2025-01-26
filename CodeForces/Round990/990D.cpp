#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define all(v) v.begin(), v.end()
#define rep(i, a, b) for(int i = a; i < b; i++)
#define each(a, b) for(auto& a : b)
typedef pair<ll, ll> pll;

int main() {
    cin.tie(NULL); ios_base::sync_with_stdio(false);
    int T; cin >> T;
    while(T--) {
        int n; cin >> n;
        vector<pll> v(n), sv(n);
        rep(i, 0, n) {
            int temp; cin >> temp;
            v[i] = {temp, i};
            sv[i] = {temp, i};
        }
        sort(all(sv)); // v is original


        vector<pll> ans;
        int start_idx = 0;
        rep(i, 0, n) {
            if(v[i].first == sv[start_idx].first) {
                ans.push_back(v[i]);
                start_idx++;
            }
        }
        ll cut = ans.back().second;
        vector<pll> sorted_remains;
        int j = 0;
        rep(i, 0, cut) {
            if(v[i] == ans[j]) {
                j++;
            } else {
                sorted_remains.push_back({v[i].first + 1, v[i].second});
            }
        }

        
        ll min_sorted_remains = sorted_remains.empty() ? 2e9 : (*min(all(sorted_remains))).first;
        rep(i, cut + 1, n) {
            if(v[i].first <= min_sorted_remains) {
                sorted_remains.push_back(v[i]);
            } else {
                sorted_remains.push_back({v[i].first + 1, v[i].second});
            }
        }


        sort(all(sorted_remains));

        each(x, sorted_remains)
            ans.push_back(x);
        
        each(x, ans) {
            cout << x.first << ' ';
        }cout << "\n";

        
    }
}