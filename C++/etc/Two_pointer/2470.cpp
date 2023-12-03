#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main() {
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(false);
    ll n;
    cin >> n;
    vector<ll> positive, negative;
    for (ll i = 0; i < n; i++) {
        ll temp;
        cin >> temp;
        if (temp > 0)
            positive.push_back(temp);
        else
            negative.push_back(temp);
    }
    sort(positive.begin(), positive.end());
    sort(negative.begin(), negative.end(), greater<ll>());

    ll pos_idx = 0, neg_idx = 0;
    ll abs_min = 2000111000;
    pair<ll, ll> abs_min_pair;
    while (pos_idx < positive.size() && neg_idx < negative.size()) {
        ll curr = positive[pos_idx] + negative[neg_idx];
        if (abs(curr) < abs_min) {
            abs_min = abs(curr);
            abs_min_pair = {negative[neg_idx], positive[pos_idx]};
        }

        if (curr < 0)
            pos_idx++;
        else if (curr > 0)
            neg_idx++;
        else
            break;
    }
    if (negative.size() >= 2) {
        if (abs_min > abs(negative[0] + negative[1])) {
            abs_min_pair = {negative[1], negative[0]};
            abs_min = abs(negative[1] + negative[0]);
        }
    }
    if (positive.size() >= 2) {
        if (abs_min > abs(positive[0] + positive[1]))
            abs_min_pair = {positive[0], positive[1]};
    }
    cout << abs_min_pair.first << " " << abs_min_pair.second;
}
