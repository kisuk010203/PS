#include <bits/stdc++.h>
using namespace std;
#define INF 1000000000
typedef struct score {
    int x, y, z; // rank
    bool operator<(const score &other) { return x < other.x; }
} score;
class segtree {
  public:
    segtree(int n) { tree.resize(n, INF); }

    int get_min(int node, int start, int end, int left, int right) {
        if (end < left || start > right)
            return INF;
        if (left <= start && end <= right)
            return tree[node];
        int mid = (start + end) / 2;
        return min(get_min((node << 1), start, mid, left, right),
                   get_min((node << 1) + 1, mid + 1, end, left, right));
    }
    int update(int node, int start, int end, int idx, int val) {
        if (idx < start || idx > end)
            return tree[node];
        if (start == end)
            return tree[node] = val;
        int mid = (start + end) / 2;
        return tree[node] =
                   min(update(node << 1, start, mid, idx, val),
                       update((node << 1) + 1, mid + 1, end, idx, val));
    }

    vector<int> tree;
};
int main() {
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    int n;
    cin >> n;
    vector<score> score_vec(n);

    int temp;
    for (int i = 0; i < n; i++) {
        cin >> temp;
        score_vec[temp - 1].x = i;
    }
    for (int i = 0; i < n; i++) {
        cin >> temp;
        score_vec[temp - 1].y = i;
    }
    for (int i = 0; i < n; i++) {
        cin >> temp;
        score_vec[temp - 1].z = i;
    }
    sort(score_vec.begin(), score_vec.end());

    segtree seg(n * 4);
    int maximal = 0;
    for (auto item : score_vec) {
        int min_el = seg.get_min(1, 0, n - 1, 0, item.y);
        if (min_el > item.z) {
            maximal++;
        }
        seg.update(1, 0, n - 1, item.y, item.z);
    }

    cout << maximal << "\n";
}