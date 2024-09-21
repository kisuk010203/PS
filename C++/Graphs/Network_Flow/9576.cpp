#include <bits/stdc++.h>
using namespace std;
#define MAXN 1010
bool visited[MAXN];    // A visited in this scope
int match[MAXN];       // B to A
vector<int> adj[MAXN]; // A to B
bool dfs(int st) {
    if (visited[st])
        return false;
    visited[st] = true;
    for (int child : adj[st]) {
        if (match[child] == -1 || dfs(match[child])) {
            match[child] = st;
            return true;
        }
    }
    return false;
}
int main() {
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    int T;
    cin >> T;
    while (T--) {
        int n, m;
        cin >> n >> m;
        fill(match, match + MAXN, -1);

        for (int i = 0; i < MAXN; i++) {
            adj[i].clear();
        }
        for (int i = 0; i < m; i++) {
            int a, b;
            cin >> a >> b;
            for (int j = a - 1; j < b; j++) {
                adj[i].push_back(j);
            }
        }

        for (int i = 0; i < m; i++) {
            fill(visited, visited + MAXN, false);
            dfs(i);
        }
        int res = 0;
        for (int i = 0; i < n; i++) {
            if (match[i] >= 0)
                res++;
        }
        cout << res << "\n";
    }
}