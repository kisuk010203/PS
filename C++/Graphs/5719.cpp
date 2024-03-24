#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii; // destination, weight
#define MAX_V 500

int n, m;
vector<pii> adj[MAX_V];
vector<pii> reverse_adj[MAX_V];
bool visited[MAX_V];
bool visit_dfs[MAX_V];
int parent[MAX_V];
int dist[MAX_V];

typedef struct path{
    int parent;
    int dest;
    int weight;
    bool operator()(const path &a, const path &b) {
        return a.weight > b.weight;
    }
} path;

void dijkstra(int start) {
    memset(visited, 0, sizeof(visited));
    memset(parent, -1, sizeof(parent));
    priority_queue<path, vector<path>, path> pq;
    pq.push({start, start, 0});
    while (!pq.empty()) {
        int u = pq.top().dest;
        int curr_dist = pq.top().weight;
        int parent_u = pq.top().parent;
        pq.pop();
        if (visited[u])
            continue;
        parent[u] = parent_u;
        dist[u] = curr_dist;
        visited[u] = true;
        for (auto child : adj[u]) {
            int next = child.first;
            int weight = child.second;
            if (!visited[next])
                pq.push({u, next, curr_dist + weight});
        }
    }
}

void delete_all_edges(int node, int cost, int dest) {
    for (auto &child : reverse_adj[node]) {
        int next = child.first;
        int weight = child.second;
        if (dist[next] + cost + weight == dist[dest]) {
            child.first = -1;
            if (!visit_dfs[next]) {
                visit_dfs[next] = true;
                delete_all_edges(next, cost + weight, dest);
            }
        }
    }
}

int main() {
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(false);
    while (true) {
        cin >> n >> m;
        if (n == 0)
            break;
        int start, dest;
        cin >> start >> dest;
        for (int i = 0; i < n; i++) {
            adj[i].clear();
            reverse_adj[i].clear();
        }
        for (int i = 0; i < m; i++) {
            int u, v, p;
            cin >> u >> v >> p;
            adj[u].push_back({v, p});
            reverse_adj[v].push_back({u, p});
        }

        dijkstra(start);
        memset(visit_dfs, 0, sizeof(visit_dfs));
        delete_all_edges(dest, 0, dest);
        
        for (int i = 0; i < n; i++) {
            adj[i].clear();
        }
        for (int i = 0; i < n; i++) {
            for (auto edge : reverse_adj[i]) {
                if (edge.first != -1)  
                    adj[edge.first].push_back({i, edge.second});
            }
        }

        dijkstra(start);
        int result = dist[dest];
        if (visited[dest] == false || result >= 5000000) {
            cout << "-1\n";
            continue;
        }

        cout << result << "\n";
    }
}