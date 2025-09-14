#include <bits/stdc++.h>
using namespace std;
int n, m, k;

void dfs(int node, vector<int> &comp, vector<vector<int>> &adj, int start) {
    comp[node] = start;
    for (int next : adj[node]) {
        if (comp[next] == -1)
            dfs(next, comp, adj, start);
    }
}
void dfsPair(int node, bool *visited, vector<set<pair<int, int>>> &adj, vector<int> &redComp) {
    visited[node] = true;
    for (auto nxt : adj[node]) {
        if (!visited[redComp[nxt.second]]){
            dfsPair(redComp[nxt.second], visited, adj, redComp);
            cout << nxt.first + 1 << " " << nxt.second + 1 << "\n";
        }
    }
}

int getComponents(vector<vector<int>> &adj, vector<int> &comp) {
    int numComp = 0;
    for (int i = 0; i < n; i++) {
        if (comp[i] == -1) {
            numComp++;
            dfs(i, comp, adj, i);
        }
    }
    return numComp;
}

void printRedCompTree(int redCompNum, vector<vector<int>> &blue, vector<int> &redComp) {
    vector<set<pair<int, int>>> redAdj(redCompNum); // start end set
    for (int i = 0; i < n; i++) {
        int cur = redComp[i];
        for (int adj : blue[i]) {
            if (redAdj[cur].find({i, adj}) == redAdj[cur].end())  {
                redAdj[cur].insert({i, adj});
            }
        }
    }
    bool visited[n];
    memset(visited, false, sizeof(visited));
    dfsPair(0, visited, redAdj, redComp);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n >> m >> k;

    vector<vector<int>> blue(n);
    vector<vector<int>> red(n);
    for (int i = 0; i < m; i++) {
        char c; int f, t;
        cin >> c >> f >> t;
        if (c == 'R') {
            red[f - 1].push_back(t - 1);
            red[t - 1].push_back(f - 1);
        }
        else {
            blue[f - 1].push_back(t - 1);
            blue[t - 1].push_back(f - 1);
        }
    }
    vector<int> redComp(n, -1);
    int redCompNum = getComponents(red, redComp);

    if (redCompNum - 1 > k) {
        cout << "0\n";
        return 0;
    }
    int requiredBlueEdges = k - redCompNum + 1;
    printRedCompTree(redCompNum, blue, redComp);

    
}