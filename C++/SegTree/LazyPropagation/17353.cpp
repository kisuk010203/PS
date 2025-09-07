#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define MAX 100010
ll arr[MAX];
ll segtree[MAX * 4];
ll lazy[MAX * 4];

ll init(int node, int start, int end) {
    if (start == end)
        return segtree[node] = arr[start];
    int mid = (start + end) / 2;
    return segtree[node] =
               init(node * 2, start, mid) + init(node * 2 + 1, mid + 1, end);
}
void update_lazy(int node, int start, int end) {
    if (lazy[node] != 0) {
        segtree[node] += (end - start + 1) * lazy[node];
        if (start != end) {
            lazy[node * 2] += lazy[node];
            lazy[node * 2 + 1] += lazy[node];
        }
        lazy[node] = 0;
    }
}
void update_range(int node, int start, int end, int left, int right, ll diff) {
    update_lazy(node, start, end);
    if (left > end || right < start)
        return;
    if (left <= start && end <= right) {
        segtree[node] += (end - start + 1) * diff;
        if (start != end) {
            lazy[node * 2] += diff;
            lazy[node * 2 + 1] += diff;
        }
        return;
    }
    int mid = (start + end) / 2;
    update_range(node * 2, start, mid, left, right, diff);
    update_range(node * 2 + 1, mid + 1, end, left, right, diff);
    segtree[node] = segtree[node * 2] + segtree[node * 2 + 1];
}
ll getsum(int node, int start, int end, int left, int right) {
    update_lazy(node, start, end);
    if (left > end || right < start)
        return 0;
    if (left <= start && end <= right)
        return segtree[node];
    int mid = (start + end) / 2;
    return getsum(node * 2, start, mid, left, right) +
           getsum(node * 2 + 1, mid + 1, end, left, right);
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, q;
    cin >> n;
    arr[0] = 0;
    int prev = 0;
    for (int i = 1; i <= n; i++) {
        int temp; cin >> temp;
        arr[i] = temp - prev;
        prev = temp;
    }
    
    init(1, 0, n);
    cin >> q;
    while (q--) {
        int mode; cin >> mode;
        if (mode == 1) {
            int l, r; cin >> l >> r;
            update_range(1, 0, n, l, r, 1);
            update_range(1, 0, n, r + 1, r + 1, -(r - l + 1));
        } else if (mode == 2) {
            int idx; cin >> idx;
            cout << getsum(1, 0, n, 0, idx) << "\n";
        } else {
            exit(1);
        }

    }
}
