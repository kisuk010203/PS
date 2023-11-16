#include <bits/stdc++.h>
using namespace std;
#define MAX 100001
vector<int> adjacent[MAX];
vector<int> childs[MAX];
int subtree[MAX];
void make_tree(int parent, int idx) {
    for (auto item : adjacent[idx]) {
        if (item == parent)
            continue;
        childs[idx].push_back(item);
        make_tree(idx, item);
    }
}
int subtree_count(int idx) {
    if (idx == 0)
        return 0;
    if (subtree[idx] != 0)
        return subtree[idx];
    int cnt = 1;
    for (auto item : childs[idx]) {
        cnt += subtree_count(item);
    }
    return subtree[idx] = cnt;
}
int main() {
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(false);
    int n, r, q;
    cin >> n >> r >> q;
    for (int i = 0; i < n - 1; i++) {
        int a, b;
        cin >> a >> b;
        adjacent[a].push_back(b);
        adjacent[b].push_back(a);
    }

    memset(subtree, 0, sizeof(subtree));
    make_tree(r, r);
    for (int i = 0; i < q; i++) {
        int idx;
        cin >> idx;
        cout << subtree_count(idx) << "\n";
    }
}
