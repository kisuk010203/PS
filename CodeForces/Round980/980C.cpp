#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> pll;
vector<pll>v;
vector<ll> all_arr;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t; cin >> t;
    while (t--){
        int n; cin >> n;
        v.clear();
        all_arr.clear();
        for (int i = 0; i < n; i++){
            int a, b; cin >> a >> b;
            v.push_back({a, b});
            all_arr.push_back(a);
            all_arr.push_back(b);
        }
        sort(all_arr.begin(), all_arr.end());
        sort(v.begin(), v.end(), [](const pll & a, const pll & b){
            int smaller_than_a = 
                lower_bound(all_arr.begin(), all_arr.end(), a.first) - all_arr.begin() + 
                lower_bound(all_arr.begin(), all_arr.end(), a.second) - all_arr.begin();
            int smaller_than_b =
                lower_bound(all_arr.begin(), all_arr.end(), b.first) - all_arr.begin() + 
                lower_bound(all_arr.begin(), all_arr.end(), b.second) - all_arr.begin();
            return smaller_than_a < smaller_than_b;    
        });
        for(auto x: v) {
            cout << x.first << " " << x.second << " ";
        }cout << "\n";


    }
    
}