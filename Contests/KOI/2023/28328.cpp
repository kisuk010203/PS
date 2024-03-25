#include <bits/stdc++.h>
using namespace std;
#define ANT_MAX 250250

int ant_num;
vector<int> adj[ANT_MAX];
vector<int> children[ANT_MAX];
int dp[ANT_MAX][2];
bool visited[ANT_MAX][2];
bool is_essential[ANT_MAX];

void dfs(int root, int parent) {
    vector<int> new_children;
    for (int child : adj[root]) {
        if (child != parent) {
            new_children.push_back(child);
            dfs(child, root);
        }
    }
    children[root] = new_children;
}
int solve_dp(int i, int j) {
    if (dp[i][j] != -1)
        return dp[i][j];
    dp[i][j] = j;
    if (j == 0) {
        for (int child : children[i]) {
            dp[i][j] += max(solve_dp(child, 0), solve_dp(child, 1));
        }
    } else {
        for (int child : children[i]) {
            dp[i][j] += solve_dp(child, 0);
        }
    }
    return dp[i][j];
}
void backtracking(int i, int j) {
    if (visited[i][j])
        return;
    visited[i][j] = true;
    is_essential[i] = is_essential[i] && (bool)j;
    for (int child : children[i]) {
        if (j == 1)
            backtracking(child, 0);
        else if (solve_dp(child, 0) > solve_dp(child, 1))
            backtracking(child, 0);
        else if (solve_dp(child, 0) < solve_dp(child, 1))
            backtracking(child, 1);
        else {
            backtracking(child, 0);
            backtracking(child, 1);
        }
    }
}
int main() {
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(false);
    cin >> ant_num;
    for (int i = 1; i < ant_num; i++) {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    dfs(1, 0);  // initialize tree structure
    memset(dp, -1, sizeof(dp));
    memset(is_essential, true, sizeof(is_essential));
    memset(visited, false, sizeof(visited));

    int zero_root = solve_dp(1, 0), one_root = solve_dp(1, 1);

    if (zero_root > one_root)
        backtracking(1, 0);
    else if (zero_root < one_root)
        backtracking(1, 1);
    else {
        backtracking(1, 0);
        backtracking(1, 1);
    }

    long long k = 0;
    for (int i = 1; i <= ant_num; i++) {
        k += (long long)is_essential[i];
    }
    long long casted_ant_num = (long long)ant_num;
    long long ans =
        (casted_ant_num * (casted_ant_num - 1)) / 2 - k * (k - 1) / 2;
    cout << ans << endl;
}
