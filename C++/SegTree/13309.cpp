#include <bits/stdc++.h>
using namespace std;

#define MAX 200200
int seg[MAX << 2];
int lzy[MAX << 2];
int sparse[MAX][20];
int depth[MAX];

int cnt;
void dfs(int cur, vector<pair<int, int>> &dfsRange, bool *visited, vector<int> *adj) {
    visited[cur] = true;
    int curStart = cnt++;
    for (int nxt : adj[cur]) {
        if (!visited[nxt]) {
            depth[nxt] = depth[cur] + 1;
            dfs(nxt, dfsRange, visited, adj);
        }
    }
    int curEnd = cnt;
    dfsRange[cur] = {curStart, curEnd - 1};
}

void propagate(int node, int st, int en) {
    if (lzy[node] != 0) {
        seg[node] += (en - st + 1) * lzy[node];
        if (st != en) {
            lzy[node << 1] += lzy[node];
            lzy[node << 1 | 1] += lzy[node];
        }
    }
    lzy[node] = 0;
}
void update(int node, int st, int en, int l, int r, int diff) {
    propagate(node, st, en);
    if (l > en || r < st) return;
    if (l <= st && en <= r) {
        seg[node] += (en - st + 1) * diff;
        if (st != en) {
            lzy[node << 1] += diff;
            lzy[node << 1 | 1] += diff;
        }
        return;
    }
    int mid = (st + en) >> 1;
    update(node << 1, st, mid, l, r, diff);
    update(node << 1 | 1, mid + 1, en, l, r, diff);
    seg[node] = seg[node << 1] + seg[node << 1 | 1];
}

int query(int node, int st, int en, int l, int r) {
    propagate(node, st, en);
    if (l > en || r < st) return 0;
    if (l <= st && en <= r) return seg[node];
    int mid = (st + en) >> 1;
    return query(node << 1, st, mid, l, r) + query(node << 1 | 1, mid + 1, en, l, r);
}

int lca(int u, int v) {
    if (depth[u] < depth[v]) swap(u, v);
    // u has larger depth
    int diff = depth[u] - depth[v];
    for (int k = 0; k < 20; k++) 
        if(diff & (1 << k)) 
            u = sparse[u][k];

    if(u == v) 
        return u;
    for(int k = 19; k >= 0; k--){
        if(sparse[u][k] != sparse[v][k]){
            u = sparse[u][k];
            v= sparse[v][k];
        }
    }
    return sparse[u][0];
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int N, Q; cin >> N >> Q;
    vector<int> parent(N, 0);
    vector<int> adj[N];
    for (int i = 1; i < N; i++) {
        cin >> parent[i];
        adj[--parent[i]].push_back(i);
    }


    for (int i = 0; i < N; i++) sparse[i][0] = parent[i];
    for (int lev = 1; lev < 20; lev++) {
        for (int i = 0; i < N; i++) {
            sparse[i][lev] = sparse[sparse[i][lev - 1]][lev - 1];
        }
    }


    vector<pair<int, int>> dfsRange(N);
    bool visited[N];
    memset(visited, 0, sizeof(visited));
    memset(depth, 0, sizeof(depth));
    dfs(0, dfsRange, visited, adj);

    
    set<int> orphans;    

    while(Q--) {
        int b, c, d; cin >> b >> c >> d;
        b--, c--;
        int lcaNode = lca(b, c);
        int bRoot = query(1, 0, N - 1, dfsRange[b].first, dfsRange[b].first);
        int cRoot = query(1, 0, N - 1, dfsRange[c].first, dfsRange[c].first);
        int lcaRoot = query(1, 0, N - 1, dfsRange[lcaNode].first, dfsRange[lcaNode].first);
        // cout << bRoot << " " << cRoot << " " << lcaRoot << " ";
        bool ans = (bRoot == cRoot) && (bRoot == lcaRoot);
        cout << (ans ? "YES" : "NO") << "\n";

        if (d == 1) {
            if (ans) {
                if (b == 0 || orphans.find(b) != orphans.end()) continue;
                update(1, 0, N - 1, dfsRange[b].first, dfsRange[b].second, 1);
                orphans.insert(b);
            } else {
                if (c == 0 || orphans.find(c) != orphans.end()) continue;
                update(1, 0, N - 1, dfsRange[c].first, dfsRange[c].second, 1);
                orphans.insert(c);
            }
        }
    }
}