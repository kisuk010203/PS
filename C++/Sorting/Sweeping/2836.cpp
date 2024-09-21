#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main() {
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    vector<pair<ll, ll>> reverse;
    ll n, m;
    cin >> n >> m;
    for (ll i = 0; i < n; i++) {
        ll a, b;
        cin >> a >> b;
        if (a > b)
            reverse.push_back({b, a});
    }
    sort(reverse.begin(), reverse.end());
    if (reverse.size() == 0) {
        cout << m;
        return 0;
    }
    ll start = reverse[0].first, end = reverse[0].second;
    ll count = 0;
    for (auto item : reverse) {
        if (item.first > end) {
            count += (end - start);
            start = item.first;
            end = item.second;
        } else if (item.first <= end) {
            end = max(end, item.second);
        }
    }
    count += (end - start);
    cout << m + count * 2 << "\n";
}