#include <bits/stdc++.h>
using namespace std;
#define MAX 10001
vector<int> adj[MAX];
vector<int> children[MAX];
int weight[MAX];
int root_dp[MAX];
int no_root_dp[MAX][2];
bool visited[MAX][3];
int find_no_root_dp(int root, bool is_parent_rooted);
void make_tree(int parent, int root) {
    for (int item : adj[root]) {
        if (item == parent)
            continue;
        children[root].push_back(item);
        make_tree(root, item);
    }
}
int find_root_dp(int root) {
    if (visited[root][0])
        return root_dp[root];
    int cnt = weight[root];
    for (int child : children[root]) {
        cnt += find_no_root_dp(child, true);
    }
    visited[root][0] = true;
    return root_dp[root] = cnt;
}
int find_no_root_dp(int root, bool is_parent_rooted) {
    int int_is_parent_rooted = (int)is_parent_rooted;
    if (visited[root][1 + int_is_parent_rooted])
        return no_root_dp[root][int_is_parent_rooted];
    int cnt = 0;
    bool is_child_rooted = false;
    for (int child : children[root]) {
        int rooted = find_root_dp(child);
        int no_rooted = find_no_root_dp(child, 0);
        cnt += max(rooted, no_rooted);
        if (rooted >= no_rooted)
            is_child_rooted = true;
    }
    if (!(is_child_rooted || is_parent_rooted)) {
        int min_diff = INT_MAX;
        for (int child : children[root]) {
            int rooted = find_root_dp(child);
            int no_rooted = find_no_root_dp(child, 0);
            min_diff = min(min_diff, no_rooted - rooted);
        }
        cnt -= min_diff;
    }
    visited[root][1 + int_is_parent_rooted] = true;
    return no_root_dp[root][int_is_parent_rooted] = cnt;
}

int main() {
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(false);

    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> weight[i + 1];
    }
    for (int i = 0; i < n - 1; i++) {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    for (int i = 0; i < MAX; i++) {
        visited[i + 1][0] = visited[i + 1][1] = visited[i + 1][2] = false;
    }

    make_tree(1, 1);
    int rooted_max = find_root_dp(1);
    int no_rooted_max = find_no_root_dp(1, false);

    cout << max(rooted_max, no_rooted_max);
}
