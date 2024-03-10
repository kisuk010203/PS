#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int segtree[2000000];
int arr[500000];
int brr[500000];
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
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
        brr[i] = arr[i];
    }
    memset(segtree, 0, sizeof(segtree));
    ll ans = 0;
    sort(brr, brr + n);
    for (int i = 0; i < n; i++) {
        arr[i] = lower_bound(brr, brr + n, arr[i]) - brr;
    }
    for (int i = 0; i < n; i++) {
        cout << query(arr[i] + 1, n - 1, 0, n - 1, 1) + 1 << "\n";
        update(0, n - 1, 1, arr[i]);
    }
}