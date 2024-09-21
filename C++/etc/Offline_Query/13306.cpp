#include <bits/stdc++.h>
using namespace std;
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

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int n, q;
    cin >> n >> q;
    vector<int> parent(n + 1);
    for (int i = 0; i < n - 1; i++) {
        cin >> parent[i + 2];
    }
    disjoint_set nodes(n + 1);
    vector<bool> buffer;
    vector<vector<int>> queries;
    for (int i = 0; i < q + n - 1; i++) {
        int x, b, c, d;
        cin >> x;
        if (x == 0) {
            cin >> b;
            queries.push_back({x, b});
        } else {
            cin >> c >> d;
            queries.push_back({x, c, d});
        }
    }
    for (int i = n + q - 2; i >= 0; i--) {
        int query_type = queries[i][0];
        if (query_type == 0) {
            nodes.merge(queries[i][1], parent[queries[i][1]]);
        } else {
            buffer.push_back(nodes.is_connected(queries[i][1], queries[i][2]));
        }
    }
    for (int i = buffer.size() - 1; i >= 0; i--) {
        cout << (buffer[i] ? "YES\n" : "NO\n");
    }
}