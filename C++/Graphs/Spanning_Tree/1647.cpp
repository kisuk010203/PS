#include <bits/stdc++.h>
using namespace std;
#define MAX 100001
typedef struct disjoint_set {
    vector<int> parent, rank;
    disjoint_set(int n) : parent(n), rank(n, 1) {
        for (int i = 0; i < n; i++)
            parent[i] = i;
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
            swap(u, v);
        parent[u] = v;
        if (rank[u] == rank[v])
            ++rank[v];
    }
} disjoint_set;

int V, E, max_cost;
vector<pair<int, int>> adj[MAX];

int kruskal() {
    int ret = 0;
    vector<pair<int, pair<int, int>>> edges;
    for (int u = 0; u < V; u++)
        for (int i = 0; i < adj[u].size(); i++) {
            int v = adj[u][i].first, cost = adj[u][i].second;
            edges.push_back(make_pair(cost, make_pair(u, v)));
        }
    sort(edges.begin(), edges.end());
    disjoint_set sets(V);
    for (int i = 0; i < edges.size(); i++) {
        int cost = edges[i].first;
        int u = edges[i].second.first, v = edges[i].second.second;
        if (sets.find(u) == sets.find(v))
            continue;
        sets.merge(u, v);
        max_cost = max(max_cost, cost);
        ret += cost;
    }
    return ret;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    max_cost = 0;
    cin >> V >> E;
    int a, b, c;
    for (int i = 0; i < E; i++) {
        cin >> a >> b >> c;
        adj[a - 1].push_back(make_pair(b - 1, c));
        adj[b - 1].push_back(make_pair(a - 1, c));
    }
    int ret = kruskal();
    cout << ret - max_cost;
}
