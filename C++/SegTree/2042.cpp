#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll arr[1000000];
ll segtree[4000000];
ll init(int left, int right, int idx) {
    if (left == right) {
        return segtree[idx] = arr[left];
    }
    int mid = (left + right) / 2;
    return segtree[idx] =
               init(left, mid, idx * 2) + init(mid + 1, right, idx * 2 + 1);
}
ll query(int query_left, int query_right, int left, int right, int idx) {
    if (query_left > right || query_right < left)
        return 0;
    if (query_left <= left && query_right >= right)
        return segtree[idx];
    int mid = (left + right) / 2;
    return query(query_left, query_right, left, mid, idx * 2) +
           query(query_left, query_right, mid + 1, right, idx * 2 + 1);
}
ll update(int target, int left, int right, int idx, ll diff) {
    if (target < left || target > right)
        return segtree[idx];
    if (left == right)
        return segtree[idx] += diff;
    int mid = (left + right) / 2;
    return segtree[idx] = update(target, left, mid, idx * 2, diff) +
                          update(target, mid + 1, right, idx * 2 + 1, diff);
}
int main() {
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(false);
    ll n, m, k;
    cin >> n >> m >> k;
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    init(0, n - 1, 1);
    for (int i = 0; i < m + k; i++) {
        ll a, b, c;
        cin >> a >> b >> c;
        if (a == 1) {
            update(b - 1, 0, n - 1, 1, c - arr[b - 1]);
            arr[b - 1] = c;
        } else {
            cout << query(b - 1, c - 1, 0, n - 1, 1) << "\n";
        }
    }
}