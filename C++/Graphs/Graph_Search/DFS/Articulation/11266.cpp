#include <bits/stdc++.h>
using namespace std;
int v, e, curr_rank, dfs_rank[10001];
bool is_articulated[10001];
vector<vector<int>> adj_list;

int find_min_reachable_rank(int node, bool is_root) {
    dfs_rank[node] = ++curr_rank;
    int res = curr_rank;
    int child_cnt = 0;

    for (auto child : adj_list[node]) {
        if (dfs_rank[child] == 0) {
            child_cnt++;
            int min_reachable_child_rank =
                find_min_reachable_rank(child, false);
            res = min(res, min_reachable_child_rank);
            if (!is_root && min_reachable_child_rank >= dfs_rank[node]) {
                is_articulated[node] = true;
            }
        } else {
            res = min(res, dfs_rank[child]);
        }
    }
    if (is_root && child_cnt >= 2) {
        is_articulated[node] = true;
    }
    return res;
}

int main() {
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(false);
    cin >> v >> e;
    adj_list.resize(v + 1);
    for (int i = 0; i < e; i++) {
        int a, b;
        cin >> a >> b;
        adj_list[a].push_back(b);
        adj_list[b].push_back(a);
    }
    for (int i = 1; i <= v; i++) {
        if (dfs_rank[i] == 0) {
            find_min_reachable_rank(i, true);
        }
    }
    vector<int> articulation_points;
    for (int i = 1; i <= v; i++) {
        if (is_articulated[i]) {
            articulation_points.push_back(i);
        }
    }
    cout << articulation_points.size() << '\n';
    for (auto point : articulation_points) {
        cout << point << ' ';
    }
}