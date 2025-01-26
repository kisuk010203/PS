#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define NMAX 100000
typedef struct sum_query{
    ll q_idx, kth, i, j;
    bool operator<(const sum_query &a) const {
        return kth < a.kth;
    }
} sum_query;
typedef struct update_query {
    ll idx, val;
} update_query;
ll seg[NMAX << 2];
ll arr[NMAX];
ll init(ll cur, ll l, ll r) {
    if(l == r) return seg[cur] = arr[l];
    ll mid = (l + r) >> 1;
    return seg[cur] = init(cur << 1, l, mid) + init(cur << 1 | 1, mid + 1, r);
}
ll update(ll cur, ll l, ll r, ll idx, ll val) {
    if(idx < l || idx > r) return seg[cur];
    if(l == r) return seg[cur] = val;
    ll mid = (l + r) >> 1;
    return seg[cur] = update(cur << 1, l, mid, idx, val) + update(cur << 1 | 1, mid + 1, r, idx, val);
}
ll query(ll cur, ll l, ll r, ll s, ll e) {
    if(e < l || r < s) return 0;
    if(s <= l && r <= e) return seg[cur];
    ll mid = (l + r) >> 1;
    return query(cur << 1, l, mid, s, e) + query(cur << 1 | 1, mid + 1, r, s, e);
}

int main(){
    cin.tie(NULL); ios_base::sync_with_stdio(false);
    ll n; cin >> n;
    for (ll i = 0; i < n; i++){
        cin >> arr[i];
    }
    ll num_query; cin >> num_query;
    vector<sum_query> sum_query_list;
    vector<update_query> update_query_list;

    for (ll i = 0; i < num_query; i++){
        ll type; cin >> type;
        if(type == 1) {
            ll idx, val; cin >> idx >> val;
            update_query_list.push_back({--idx, val});
        } else {
            ll kth, i, j; cin >> kth >> i >> j;
            sum_query_list.push_back({(ll)sum_query_list.size(), kth, --i, --j});
        }
    }
    sort(sum_query_list.begin(), sum_query_list.end());
    init(1, 0, n - 1);
    ll update_query_idx = 0;
    vector<ll> ans(sum_query_list.size());

    for (ll i = 0; i < sum_query_list.size(); i++) {
        ll kth = sum_query_list[i].kth;
        ll s = sum_query_list[i].i;
        ll e = sum_query_list[i].j;
        while(update_query_idx < kth) {
            update(1, 0, n - 1, update_query_list[update_query_idx].idx, update_query_list[update_query_idx].val);
            update_query_idx++;
        }
        ll res = query(1, 0, n - 1, s, e);
        ans[sum_query_list[i].q_idx] = res;

    }
    for(auto a : ans) cout << a << "\n";

}