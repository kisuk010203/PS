#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main() {
    int n;
    cin >> n;
    vector<pair<ll, ll>> v;
    for (int i = 0; i < n; i++) {
        ll x, y;
        cin >> x >> y;
        v.push_back({x, y});
    }
    ll dist_min = 990909090L;
    pair<int, int> ans;
    for (int i = 0; i < n; i++) {
        ll dist_max = 0;
        for (int j = 0; j < n; j++) {
            dist_max = max(
                dist_max,
                (v[j].first - v[i].first) * (v[j].first - v[i].first) +
                    (v[j].second - v[i].second) * (v[j].second - v[i].second));
        }
        if (dist_max < dist_min) {
            dist_min = dist_max;
            ans = v[i];
        }
    }
    cout << ans.first << " " << ans.second << "\n";
}