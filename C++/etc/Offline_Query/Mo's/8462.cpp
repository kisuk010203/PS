#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int n, t, block_size;
ll ans;
typedef struct Query {
    int l, r, idx;
    bool operator<(Query other) {
        if (l/block_size != other.l/block_size)
            return l/block_size < other.l/block_size;
        return r < other.r;
    }
} Query;
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n, t; cin >> n >> t;
    block_size = sqrt(n);

    int arr[n];
    vector<Query> queries(t);
    vector<ll> ans_vec(t);
    int freq[(int)1e6 + 1];

    for (int i = 0; i < n; i++) cin >> arr[i];
    for (int i = 0; i < t; i++) {
        cin >> queries[i].l >> queries[i].r;
        queries[i].l--; queries[i].r--;
        queries[i].idx = i;
    }

    sort(queries.begin(), queries.end());
    memset(freq, 0, sizeof(freq));

    int l = 0, r = -1;
    for (Query query : queries) {
        while (l > query.l) {
            l--;
            freq[arr[l]]++;
            ans += (ll)arr[l] * (2 * freq[arr[l]] - 1);
        } 
        while (l < query.l) {
            freq[arr[l]]--;
            ans -= (ll)arr[l] * (2 * freq[arr[l]] + 1);
            l++;
        }   
        while (r < query.r) {
            r++;
            freq[arr[r]]++;
            ans += (ll)arr[r] * (2 * freq[arr[r]] - 1);
        }
        while (r > query.r) {
            freq[arr[r]]--;
            ans -= (ll)arr[r] * (2 * freq[arr[r]] + 1);
            r--;
        }
        ans_vec[query.idx] = ans;
    }
    for(ll item : ans_vec) cout << item << "\n";
}