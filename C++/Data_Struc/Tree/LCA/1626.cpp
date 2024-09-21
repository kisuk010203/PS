#include <bits/stdc++.h>
using namespace std;
#define NMAX 50000
typedef long long ll;
typedef pair<int, ll> pil;
typedef pair<int, int> pii;
typedef struct disjoint_set {
    vector<int> parent, rank;
    disjoint_set(int n) : parent(n), rank(n, 1) {
        for (int i = 0; i < n; i++) {
            parent[i] = i;
        }
    }
    int find(int u) {
        if (u == parent[u])
            return u;
        return parent[u] = find(parent[u]);
    }
    void merge(int u, int v) {
        u = find(u);
        v = find(v);
        if (u == v)
            return;
        if (rank[u] > rank[v])
            swap(u, v); // u has smaller rank
        parent[u] = v;  // merge smaller group to larger group
        if (rank[u] == rank[v])
            ++rank[v];
    }
    bool is_connected(int u, int v) {
        u = find(u);
        v = find(v);
        return u == v;
    }
} disjoint_set;

vector<pil> adj[NMAX];
vector<pil> mst[NMAX];
bool visited[NMAX];
int depth[NMAX];
int par[NMAX][20];
ll longest_edge[NMAX][20];
ll second_longest_edge[NMAX][20];

int V, E, mstcnt;

ll kruskal() {
    ll ret = 0L;
    vector<pair<ll, pii>> edges;
    for (int i = 0; i < V; i++) {
        for (auto item : adj[i]) {
            int j = item.first;
            ll weight = item.second;
            edges.push_back({weight, {i, j}});
        }
    }
    sort(edges.begin(), edges.end());
    disjoint_set sets(V);
    for (auto edge : edges) {
        ll weight = edge.first;
        int u = edge.second.first, v = edge.second.second;
        if (sets.is_connected(u, v))
            continue;
        sets.merge(u, v);
        ret += weight;
        mstcnt++;
        mst[u].push_back({v, weight});
        mst[v].push_back({u, weight});
    }
    return ret;
}
void find_depth(int curr) {
    visited[curr] = true;
    for (auto child_pair : mst[curr]) {
        int child = child_pair.first;
        ll weight = child_pair.second;
        if (!visited[child]) {
            int exp = 1;
            par[child][0] = curr;
            longest_edge[child][0] = weight;
            while (par[par[child][exp - 1]][exp - 1] != -1) {
                par[child][exp] = par[par[child][exp - 1]][exp - 1];
                longest_edge[child][exp] =
                    max(longest_edge[child][exp - 1],
                        longest_edge[par[child][exp - 1]][exp - 1]);
                if (longest_edge[child][exp - 1] != longest_edge[child][exp]) {
                    second_longest_edge[child][exp] =
                        max(longest_edge[child][exp - 1],
                            second_longest_edge[par[child][exp - 1]][exp - 1]);
                } else if (longest_edge[par[child][exp - 1]][exp - 1] !=
                           longest_edge[child][exp]) {
                    second_longest_edge[child][exp] =
                        max(longest_edge[par[child][exp - 1]][exp - 1],
                            second_longest_edge[child][exp - 1]);
                } else {
                    second_longest_edge[child][exp] =
                        max(second_longest_edge[child][exp - 1],
                            second_longest_edge[par[child][exp - 1]][exp - 1]);
                }
                exp++;
            }
            depth[child] = depth[curr] + 1;
            find_depth(child);
        }
    }
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> V >> E;
    for (int i = 0; i < V; i++) {
        fill(par[i], par[i] + 20, -1);
        fill(longest_edge[i], longest_edge[i] + 20, -1);
        fill(second_longest_edge[i], second_longest_edge[i] + 20, -1);
    }
    vector<pair<ll, pii>> edges;
    for (int i = 0; i < E; i++) {
        int u, v;
        ll w;
        cin >> u >> v >> w;
        u--, v--;
        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
        edges.push_back({w, {u, v}});
    }
    ll mst_val = kruskal();
    ll smst_val = (1L << 33);

    find_depth(0);
    for (auto item : edges) {
        ll weight = item.first;
        int u = item.second.first;
        int v = item.second.second;
        if (depth[u] < depth[v])
            swap(u, v);
        ll longest = -1;
        ll second_longest = -2;
        // cout << depth[u] << " " << depth[v] << " ";
        if (depth[u] > depth[v]) {
            int diff = depth[u] - depth[v];
            while (diff > 0) {
                for (int i = 19; i >= 0; i--) {
                    if (diff >= (1 << i)) {
                        if (longest_edge[u][i] > longest) {
                            second_longest = longest;
                            longest = longest_edge[u][i];
                        } else if (longest > longest_edge[u][i])
                            second_longest =
                                max(second_longest, longest_edge[u][i]);
                        second_longest =
                            max(second_longest_edge[u][i], second_longest);
                        diff -= (1 << i);
                        u = par[u][i];
                    }
                }
            }
        }

        for (int i = 19; i >= 0; i--) {
            if (par[u][i] != par[v][i]) {
                if (longest < longest_edge[u][i]) {
                    second_longest = longest;
                    longest = longest_edge[u][i];
                } else if (longest > longest_edge[u][i])
                    second_longest = max(second_longest, longest_edge[u][i]);
                if (longest < longest_edge[v][i]) {
                    second_longest = longest;
                    longest = longest_edge[v][i];
                } else if (longest > longest_edge[v][i])
                    second_longest = max(second_longest, longest_edge[v][i]);
                second_longest =
                    max(second_longest, max(second_longest_edge[u][i],
                                            second_longest_edge[v][i]));
                u = par[u][i];
                v = par[v][i];
            }
        }

        if (u != v) {
            if (longest < longest_edge[u][0]) {
                second_longest = longest;
                longest = longest_edge[u][0];
            } else if (longest > longest_edge[u][0])
                second_longest = max(second_longest, longest_edge[u][0]);
            if (longest < longest_edge[v][0]) {
                second_longest = longest;
                longest = longest_edge[v][0];
            } else if (longest > longest_edge[v][0])
                second_longest = max(second_longest, longest_edge[v][0]);
            second_longest =
                max(second_longest,
                    max(second_longest_edge[u][0], second_longest_edge[v][0]));
        }
        if (longest != weight)
            smst_val = min(smst_val, mst_val - longest + weight);
        else if (second_longest >= 0)
            smst_val = min(smst_val, mst_val - second_longest + weight);
    }
    if (mstcnt != V - 1 || smst_val == (1L << 33))
        cout << "-1\n";
    else
        cout << smst_val << "\n";
}