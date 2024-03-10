#include <iostream>
#include <vector>
typedef long long ll;
std::vector<ll> arr(1000009);
std::vector<ll> segtree(4000009);

ll init(int node, int start, int end) {
    if (start == end)
        return segtree[node] = arr[start];
    int mid = (start + end) / 2;
    return segtree[node] =
               init(node * 2, start, mid) + init(node * 2 + 1, mid + 1, end);
}
void update(int node, int start, int end, int idx, ll dif) {
    if (idx < start || idx > end)
        return;
    segtree[node] += dif;
    if (start != end) {
        int mid = (start + end) / 2;
        update(node * 2, start, mid, idx, dif);
        update(node * 2 + 1, mid + 1, end, idx, dif);
    }
}
ll getsum(int node, int start, int end, int left, int right) {
    if (left > end || right < start)
        return 0;
    if (left <= start && end <= right)
        return segtree[node];
    int mid = (start + end) / 2;
    return getsum(node * 2, start, mid, left, right) +
           getsum(node * 2 + 1, mid + 1, end, left, right);
}
int main() {
    int n, m, k;
    std::cin >> n >> m >> k;

    for (int i = 0; i < n; i++)
        std::cin >> arr[i];
    init(1, 0, n - 1);
    for (int i = 0; i < m + k; i++) {
        ll a, b, c;
        std::cin >> a >> b >> c;
        if (a == 1) {
            update(1, 0, n - 1, b - 1, c - arr[b - 1]);
            arr[b - 1] = c;
        } else {
            std::cout << getsum(1, 0, n - 1, b - 1, c - 1) << std::endl;
        }
    }
}
