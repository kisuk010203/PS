#include <bits/stdc++.h>
using namespace std;
#define all(v) v.begin(), v.end()
#define sz 131072
typedef long long ll;
int n;
int arr[sz];
vector<int> merge_tree[sz * 2];
void init() {
    for (int i = 0; i < n; i++) {
        merge_tree[i + sz].push_back(arr[i]);
    }
    for (int i = sz - 1; i > 0; i--) {
        merge_tree[i].resize(merge_tree[i * 2].size() +
                             merge_tree[i * 2 + 1].size());
        merge(all(merge_tree[i * 2]), all(merge_tree[i * 2 + 1]),
              merge_tree[i].begin());
    }
}
int smaller_than_target_query(int left, int right, int target) {
    int ret = 0;
    while (left <= right) {
        if (left % 2 == 1) {
            ret += upper_bound(all(merge_tree[left]), target) -
                   merge_tree[left].begin();
            left++;
        }
        if (right % 2 == 0) {
            ret += upper_bound(all(merge_tree[right]), target) -
                   merge_tree[right].begin();
            right--;
        }
        left /= 2, right /= 2;
    }
    return ret;
}
int query(int left, int right, int k) {
    int start = -1e9;
    int end = 1e9;
    while(start <= end) {
        int mid = (start + end) / 2;
        int res = smaller_than_target_query(left, right, mid);
        if(res < k)
            start = mid + 1;
        else
            end = mid - 1;
    }
    return start;
}

int main() {
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(false);
    int q;
    cin >> n >> q;
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    init();
    sort(arr, arr + n);
    while (q--) {
        int left, right, k;
        cin >> left >> right >> k;
        cout << query(sz + left - 1, sz + right - 1, k) << "\n";
    }
}