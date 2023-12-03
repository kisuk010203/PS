#include <bits/stdc++.h>
using namespace std;
#define MAX 10001
vector<int> adj[MAX];
vector<int> children[MAX];
vector<int> ans;
int weight[MAX];
int root_dp[MAX];
int no_root_dp[MAX];
bool visited[MAX][2];
int find_no_root_dp(int root);
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
        cnt += find_no_root_dp(child);
    }
    visited[root][0] = true;
    return root_dp[root] = cnt;
}
int find_no_root_dp(int root) {
    if (visited[root][1])
        return no_root_dp[root];
    int cnt = 0;
    for (int child : children[root]) {
        int rooted = find_root_dp(child);
        int no_rooted = find_no_root_dp(child);
        cnt += max(rooted, no_rooted);
    }
    visited[root][1] = true;
    return no_root_dp[root] = cnt;
}
void backtracking(int rooted, int root) {
    if (rooted) {
        ans.push_back(root);
        for (int child : children[root]) {
            backtracking(0, child);
        }
    } else {
        for (int child : children[root]) {
            bool child_rooted = find_root_dp(child) > find_no_root_dp(child);
            backtracking(child_rooted, child);
        }
    }
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
        visited[i + 1][0] = visited[i + 1][1] = false;
    }

    make_tree(1, 1);
    int rooted_max = find_root_dp(1);
    int no_rooted_max = find_no_root_dp(1);
    bool is_rooted = rooted_max > no_rooted_max;

    backtracking(is_rooted, 1);
    sort(ans.begin(), ans.end());
    if (is_rooted) {
        cout << rooted_max << "\n";
    } else
        cout << no_rooted_max << "\n";
    for (int item : ans)
        cout << item << " ";
}
