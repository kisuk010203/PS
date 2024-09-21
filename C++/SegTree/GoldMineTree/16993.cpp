#include <bits/stdc++.h>
using namespace std;
#define ll long long

int N;
struct TreeNode {
    ll sum, lmax, rmax, tmax;
};

TreeNode seg[400004];
int arr[100000];

TreeNode get_sum(int cur, int left, int right, int start, int end) {
    TreeNode temp;
    temp.sum = temp.lmax = temp.rmax = temp.tmax = -1000000000;
    if (start > right || left > end)
        return temp;
    if (left >= start && right <= end)
        return seg[cur];

    int mid = (left + right) / 2;
    TreeNode lNode, rNode;
    lNode = get_sum(cur * 2, left, mid, start, end);
    rNode = get_sum(cur * 2 + 1, mid + 1, right, start, end);

    temp.sum = lNode.sum + rNode.sum;
    temp.lmax = max(lNode.lmax, lNode.sum + rNode.lmax);
    temp.rmax = max(rNode.rmax, rNode.sum + lNode.rmax);
    temp.tmax = max({lNode.tmax, rNode.tmax, lNode.rmax + rNode.lmax});
    return temp;
}
void update(int cur, int left, int right) {

    if (left == right) {
        seg[cur].sum = arr[left];
        seg[cur].lmax = arr[left];
        seg[cur].rmax = arr[left];
        seg[cur].tmax = arr[left];
        return;
    }
    int mid = (left + right) / 2;
    update(cur * 2, left, mid);
    update(cur * 2 + 1, mid + 1, right);

    int lnode = cur * 2, rnode = cur * 2 + 1;
    seg[cur].sum = seg[lnode].sum + seg[rnode].sum;
    seg[cur].lmax = max(seg[lnode].lmax, seg[lnode].sum + seg[rnode].lmax);
    seg[cur].rmax = max(seg[rnode].rmax, seg[rnode].sum + seg[lnode].rmax);
    seg[cur].tmax = max(
        {seg[lnode].tmax, seg[rnode].tmax, seg[lnode].rmax + seg[rnode].lmax});
    return;
}
void initi() {
    for (int i = 0; i < 400004; i++) {
        TreeNode temp;
        temp.sum = 0;
        temp.lmax = temp.rmax = temp.tmax = -1000000000;
        seg[i] = temp;
    }
}

int main() {
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    cin >> N;

    for (int i = 0; i < N; i++) {
        cin >> arr[i];
    }
    update(1, 0, N - 1);

    int q;
    cin >> q;
    while (q--) {
        int start, end;
        cin >> start >> end;
        start--;
        end--;
        TreeNode res = get_sum(1, 0, N - 1, start, end);
        cout << res.tmax << "\n";
    }
    return 0;
}