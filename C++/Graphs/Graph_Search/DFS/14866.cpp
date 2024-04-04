#include <bits/stdc++.h>
using namespace std;
vector<vector<int>> adj_list;
vector<int> dfs_rank;
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
        adj_list[n].push_back(a);
    }
}