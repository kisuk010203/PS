#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main() {
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(false);
    ll n, cap;
    unordered_map<ll, ll> first_dict, second_dict;
    vector<ll> bags;

    cin >> n >> cap;
    for (int i = 0; i < n; i++) {
        ll temp;
        cin >> temp;
        bags.push_back(temp);
    }

    if (n == 1) {
        cout << ((bags[0] <= cap) ? 2 : 1);
        return 0;
    }
    for (int i = 0; i < (1 << (n / 2)); i++) {
        ll curr_cap = 0;
        for (int j = 0; j < n / 2; j++) {
            if (i & (1 << j))
                curr_cap += bags[j];
        }
        if (first_dict.find(curr_cap) != first_dict.end())
            first_dict[curr_cap]++;
        else
            first_dict[curr_cap] = 1;
    }
    for (int i = 0; i < (1 << (n - n / 2)); i++) {
        ll curr_cap = 0;
        for (int j = 0; j < n - n / 2; j++) {
            if (i & (1 << j))
                curr_cap += bags[n / 2 + j];
        }
        if (second_dict.find(curr_cap) != second_dict.end())
            second_dict[curr_cap]++;
        else
            second_dict[curr_cap] = 1;
    }

    vector<pair<ll, ll>> first_vec(first_dict.begin(), first_dict.end());
    vector<pair<ll, ll>> second_vec(second_dict.begin(), second_dict.end());
    sort(first_vec.begin(), first_vec.end());
    sort(second_vec.begin(), second_vec.end());
    vector<ll> accum_second_vec;
    ll cnt = 0;
    accum_second_vec.push_back(cnt);
    for (auto item : second_vec) {
        cnt += item.second;
        accum_second_vec.push_back(cnt);
    }
    ll ans = 0;
    for (pair<ll, ll> item : first_vec) {
        if (item.first > cap)
            continue;

        pair<ll, ll> p = {cap - item.first, LONG_LONG_MAX};
        if (upper_bound(second_vec.begin(), second_vec.end(), p) ==
            second_vec.end()) {
            ans += item.second * accum_second_vec[second_vec.size()];
        } else
            ans += item.second *
                   accum_second_vec[upper_bound(second_vec.begin(),
                                                second_vec.end(), p) -
                                    second_vec.begin()];
    }

    cout << ans << endl;
}
