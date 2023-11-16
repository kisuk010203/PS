#include <bits/stdc++.h>
using namespace std;
#define MAX 1000001
vector<int> adj[MAX];
vector<int> children[MAX];
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
    int cnt = 1;
    for (int child : children[root]) {
        cnt += min(find_root_dp(child), find_no_root_dp(child));
    }
    visited[root][0] = true;
    return root_dp[root] = cnt;
}
int find_no_root_dp(int root) {
    if (visited[root][1])
        return no_root_dp[root];
    int cnt = 0;
    for (int child : children[root]) {
        cnt += find_root_dp(child);
    }
    visited[root][1] = true;
    return no_root_dp[root] = cnt;
}

int main() {
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(false);

    int n;
    cin >> n;

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
    cout << min(rooted_max, no_rooted_max);
}
