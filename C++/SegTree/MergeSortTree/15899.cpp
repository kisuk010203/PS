#include <bits/stdc++.h>
using namespace std;

#define MAX_N 200000
#define MOD 1000000007
#define sz 262144
#define all(v) v.begin(), v.end()

typedef long long ll;
typedef struct {
    int color;
    int preorder_idx;
    int subtree_count;
} Node;

Node nodes[MAX_N];
vector<int> adj[MAX_N];  // adj list by index
vector<int>
    merge_tree[sz * 2];  // this only consists of colors, by preorder_idx
unordered_map<int, int> preorder_to_name;
int n, q, c;
int counter = 0;

void preorder(int root, int prev) {
    nodes[root].preorder_idx = counter++;
    for (int child : adj[root]) {
        if (child != prev)
            preorder(child, root);
    }
    nodes[root].subtree_count = counter - nodes[root].preorder_idx;
    preorder_to_name[nodes[root].preorder_idx] = root;
}
void init() {
    for (int i = 0; i < n; i++) {
        merge_tree[i + sz].push_back(nodes[preorder_to_name[i]].color);
    }
    for (int i = sz - 1; i > 0; i--) {
        merge_tree[i].resize(merge_tree[i * 2].size() +
                             merge_tree[i * 2 + 1].size());
        merge(all(merge_tree[i * 2]), all(merge_tree[i * 2 + 1]),
              merge_tree[i].begin());
    }
}
ll query(int left, int right, int target) {
    ll ret = 0;
    while (left <= right) {
        if (left % 2 == 1) {
            ret += upper_bound(all(merge_tree[left]), target) -
                   merge_tree[left].begin();
            ret %= MOD;
            left++;
        }
        if (right % 2 == 0) {
            ret += upper_bound(all(merge_tree[right]), target) -
                   merge_tree[right].begin();
            ret %= MOD;
            right--;
        }
        left /= 2, right /= 2;
    }
    return ret;
}

int main() {
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(false);
    cin >> n >> q >> c;
    for (int i = 0; i < n; i++) {
        int color;
        cin >> color;
        nodes[i].color = color;
    }
    for (int i = 0; i < n - 1; i++) {
        int x, y;
        cin >> x >> y;
        adj[--x].push_back(--y);
        adj[y].push_back(x);
    }
    preorder(0, -1);
    init();
    ll ret = 0;
    for (int i = 0; i < q; i++) {
        int root, target;
        cin >> root >> target;
        root--;
        ret +=
            query(sz + nodes[root].preorder_idx,
                  sz + nodes[root].preorder_idx + nodes[root].subtree_count - 1,
                  target);
        ret %= MOD;
    }
    cout << ret << "\n";
}