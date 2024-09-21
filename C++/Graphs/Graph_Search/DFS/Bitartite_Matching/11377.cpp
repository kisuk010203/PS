#include <bits/stdc++.h>
using namespace std;
#define MAXN 2020
int n, m, k;
vector<int> adj[MAXN];
bool visited[MAXN];
int matching[MAXN];
bool dfs(int st) {
    if (visited[st])
        return false;
    visited[st] = true;
    for (int child : adj[st]) {
        if (matching[child] == -1 || dfs(matching[child])) {
            matching[child] = st;
            return true;
        }
    }
    return false;
}
int main() {
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    cin >> n >> m >> k;
    for (int i = 0; i < n; i++) {
        int temp;
        cin >> temp;
        for (int j = 0; j < temp; j++) {
            int job;
            cin >> job;
            adj[i].push_back(job);
            adj[i + n].push_back(job);
        }
    }

    int cnt1 = 0, cnt2 = 0;
    fill(matching, matching + MAXN, -1);
    for (int i = 0; i < n; i++) {
        memset(visited, false, sizeof(visited));
        if (dfs(i))
            cnt1++;
    }
    for (int i = n; i < 2 * n; i++) {
        memset(visited, false, sizeof(visited));
        if (dfs(i))
            cnt2++;
        if (cnt2 == k)
            break;
    }
    cout << cnt1 + cnt2 << "\n";
}