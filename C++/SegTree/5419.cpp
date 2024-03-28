#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> pll;
pll arr[75000];
pair<pll, int> brr[75000];
int segtree[300000];
ll query(int q_left, int q_right, int left, int right, int idx) {
    if (q_right < left || q_left > right)
        return 0;
    if (q_left <= left && q_right >= right)
        return segtree[idx];
    int mid = (left + right) / 2;
    return query(q_left, q_right, left, mid, idx * 2) +
           query(q_left, q_right, mid + 1, right, idx * 2 + 1);
}
void update(int left, int right, int idx, int target) {
    if (target < left || target > right)
        return;
    segtree[idx]++;
    if (left == right)
        return;
    int mid = (left + right) / 2;
    update(left, mid, idx * 2, target);
    update(mid + 1, right, idx * 2 + 1, target);
}
int main() {
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(false);
    int T;
    cin >> T;
    while (T--) {
        int n;
        cin >> n;
        for (int i = 0; i < n; i++) {
            cin >> arr[i].first >> arr[i].second;
            brr[i] = {arr[i], i};
        }
        memset(segtree, 0, sizeof(segtree));
        sort(brr, brr + n, [](pair<pll, int> a, pair<pll, int> b) -> bool {
            if (a.first.second == b.first.second)
                return a.first.first > b.first.first;
            return a.first.second < b.first.second;
        });  // sorted by y
        for (int i = 0; i < n; i++)
            arr[brr[i].second].second = i;
        sort(arr, arr + n, [](pll a, pll b) -> bool {
            if (a.first == b.first)
                return a.second > b.second;
            else
                return a.first < b.first;
        });  // sorted by x
        ll ans = 0;
        for (int i = 0; i < n; i++) {
            ans += query(arr[i].second + 1, n - 1, 0, n - 1, 1);
            update(0, n - 1, 1, arr[i].second);
        }
        cout << ans << "\n";
    }
}