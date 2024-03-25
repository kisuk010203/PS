#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define MAX 100001
ll n;
ll ans;
ll segtree[4 * MAX];
ll sumsegtree[4 * MAX];
ll arr[MAX];
ll init(ll node, ll left, ll right) {
    if (left == right)
        return segtree[node] = left;
    ll mid = (left + right) / 2;
    ll cand1 = init(node * 2, left, mid);
    ll cand2 = init(node * 2 + 1, mid + 1, right);
    return segtree[node] = ((arr[cand1] > arr[cand2]) ? cand2 : cand1);
}
ll init_sum(ll node, ll left, ll right) {
    if (left == right)
        return sumsegtree[node] = arr[left];
    ll mid = (left + right) / 2;
    return sumsegtree[node] = init_sum(2 * node, left, mid) +
                              init_sum(2 * node + 1, mid + 1, right);
}
ll find_min(ll node, ll left, ll right, ll start, ll end) {
    if (left > end || start > right)
        return 100000;
    if (start <= left && right <= end)
        return segtree[node];
    ll mid = (left + right) / 2;
    ll cand1 = find_min(node * 2, left, mid, start, end);
    ll cand2 = find_min(node * 2 + 1, mid + 1, right, start, end);
    return ((arr[cand1] > arr[cand2]) ? cand2 : cand1);
}
ll getsum(ll node, ll left, ll right, ll start, ll end) {
    if (left > end || start > right)
        return 0;
    if (start <= left && right <= end)
        return sumsegtree[node];
    ll mid = (left + right) / 2;
    return getsum(2 * node, left, mid, start, end) +
           getsum(2 * node + 1, mid + 1, right, start, end);
}
void subseq(ll left, ll right) {
    if (left > right)
        return;
    if (left == right) {
        ans = max(ans, arr[left] * arr[left]);
        return;
    }
    ll target = find_min(1, 0, n - 1, left, right);
    ans = max(ans, arr[target] * getsum(1, 0, n - 1, left, right));
    subseq(left, target - 1);
    subseq(target + 1, right);
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n;
    for (ll i = 0; i < n; i++)
        cin >> arr[i];
    arr[100000] = 10000000;
    ans = 0;
    init(1, 0, n - 1);
    init_sum(1, 0, n - 1);

    subseq(0, n - 1);
    cout << ans;
}
