#include <bits/stdc++.h>
using namespace std;
int sum_leaf_depth;
vector<int> searched;
vector<int> adj[500000];
void dfs(int start, int depth) {
    bool is_leaf = true;
    searched[start] = 1;
    for (int next : adj[start]) {
        if (searched[next])
            continue;
        is_leaf = false;
        dfs(next, depth + 1);
    }
    if (is_leaf)
        sum_leaf_depth += (depth & 1);
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n;
    cin >> n;
    for (int i = 0; i < n - 1; i++) {
        int a, b;
        cin >> a >> b;
        a--;
        b--;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    searched.assign(n, 0);
    dfs(0, 0);
    cout << ((sum_leaf_depth % 2 == 1) ? "Yes" : "No");
}