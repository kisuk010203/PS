#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
int segtree[2000000];
int arr[500000];
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
    int n;
    cin >> n;
    unordered_map<int, int> serial_to_idx;
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
        serial_to_idx[arr[i]] = i;
    }
    memset(segtree, 0, sizeof(segtree));
    ll ans = 0;
    for (int i = 0; i < n; i++) {
        int temp;
        cin >> temp;
        int idx = serial_to_idx[temp];
        ans += query(idx + 1, n - 1, 0, n - 1, 1);
        update(0, n - 1, 1, idx);
    }
    cout << ans << "\n";
}