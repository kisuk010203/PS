#include <iostream>
#define MAX 100009
using namespace std;
typedef long long ll;
ll n;
ll arr[MAX];
ll segtree[MAX * 4];
ll min(ll a, ll b) {
    if (a == -1 || b == -1)
        return a + b + 1;
    return (arr[a] > arr[b]) ? b : a;
}
ll max(ll a, ll b, ll c) {
    ll temp = (a > b) ? a : b;
    return (temp > c) ? temp : c;
}
ll init(ll node, ll start, ll end) {
    if (start == end)
        return segtree[node] = start;
    ll mid = (start + end) / 2;
    return segtree[node] = min(init(2 * node, start, mid),
                               init(2 * node + 1, mid + 1, end));
}
ll findmin(ll node, ll start, ll end, ll left, ll right) {
    if (left > end || right < start)
        return -1;
    else if (left <= start && end <= right)
        return segtree[node];
    ll mid = (start + end) / 2;
    return min(findmin(node * 2, start, mid, left, right),
               findmin(node * 2 + 1, mid + 1, end, left, right));
}
ll dnc(ll start, ll end) {
    ll temp = findmin(1, 0, n - 1, start, end);
    ll temp_max = arr[temp] * (end - start + 1);
    ll left_max = (start < temp) ? dnc(start, temp - 1) : 0;
    ll right_max = (end > temp) ? dnc(temp + 1, end) : 0;
    return max(temp_max, left_max, right_max);
}
int main() {
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(false);
    cin >> n;
    for (ll i = 0; i < n; i++)
        cin >> arr[i];
    init(1, 0, n - 1);
    cout << dnc(0, n - 1) << endl;
}