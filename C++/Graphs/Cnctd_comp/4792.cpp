#include <bits/stdc++.h>
using namespace std;
int n, m, k;
vector<vector<int>> blue;
vector<vector<int>> red;
void dfs(int node, bool *visited, vector<vector<int>> &adj) {
    visited[node] = true;
    for (int next : adj[node]) {
        if (!visited[next]) {
            dfs(next, visited, adj);
        }
    }
}
int getComponents(vector<vector<int>> &adj) {
    bool visited[n];
    memset(visited, false, sizeof(visited));
    int components = 0;
    for (int i = 0; i < n; i++) {
        if (!visited[i]) {
            components++;
            dfs(i, visited, adj);
        }
    }
    return components;
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    while (true) {
        cin >> n >> m >> k;
        if (n == 0 && m == 0 && k == 0) break;
        red.clear();
        blue.clear();
        red.resize(n);
        blue.resize(n);
        for (int i = 0; i < m; i++) {
            char c;
            int f, t; 
            cin >> c >> f >> t;
            if (c == 'R') {
                red[f - 1].push_back(t - 1);
                red[t - 1].push_back(f - 1);
            } else {
                blue[f - 1].push_back(t - 1);
                blue[t - 1].push_back(f - 1);
            }
        }
        int redComp = getComponents(red);
        int blueComp = getComponents(blue);

        int minBlueEdges = redComp - 1;
        int maxBlueEdges = n - blueComp;
        if (k >= minBlueEdges && k <= maxBlueEdges) {
            cout << 1 << "\n";
        } else {
            cout << 0 << "\n";
        }

    }
}