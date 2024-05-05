#include <bits/stdc++.h>
using namespace std;
int curr_rank;
vector<vector<int>> adj_list;
vector<int> dfs_rank;
bool ans = true;
int find_reachable_min(int node, int parent) {
    int ret = dfs_rank[node] = ++curr_rank;
    int cycles = 0;
    for (auto child : adj_list[node]) {
        if (child == parent)
            continue;
        if (dfs_rank[child] == 0) {
            int temp = find_reachable_min(child, node);
            ret = min(ret, temp);
            if (dfs_rank[node] > temp)
                cycles++;
        } else {
            ret = min(ret, dfs_rank[child]);
            cycles++;
        }
    }
    if (cycles >= 2)
        ans = false;
    return ret;
}
int main() {
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(false);
    int n, m;
    cin >> n >> m;

    adj_list.resize(n + 1);
    dfs_rank.resize(n + 1);
    fill(dfs_rank.begin(), dfs_rank.end(), 0);

    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        adj_list[a].push_back(b);
        adj_list[b].push_back(a);
    }
    find_reachable_min(1, 1);
    cout << (ans ? "" : "Not ") << "Cactus\n";
}