#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main() {
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(false);
    ll n, k;
    cin >> n >> k;
    vector<ll> quest;
    for (ll i = 0; i < n; i++) {
        ll temp;
        cin >> temp;
        quest.push_back(temp);
    }
    sort(quest.begin(), quest.end());

    ll ans = 0;
    for (ll i = 0; i < n; i++) {
        ans += min(i, k) * quest[i];
    }
    cout << ans << "\n";
}
