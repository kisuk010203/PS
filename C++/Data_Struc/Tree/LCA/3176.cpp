#include <bits/stdc++.h>
using namespace std;
#define NMAX 100000
typedef long long ll;
typedef pair<int, ll> pil;

vector<pil> adj[NMAX];
int depth[NMAX];
bool visited[NMAX];
int par[NMAX][20];
ll longest_dist[NMAX][20];
ll shortest_dist[NMAX][20];

void find_depth(int curr) {
    visited[curr] = true;
    for (auto child_pair : adj[curr]) {
        int child = child_pair.first;
        ll weight = child_pair.second;
        if (!visited[child]) {
            int exp = 1;
            par[child][0] = curr;
            longest_dist[child][0] = shortest_dist[child][0] = weight;
            while (par[par[child][exp - 1]][exp - 1] != -1) {
                par[child][exp] = par[par[child][exp - 1]][exp - 1];
                longest_dist[child][exp] =
                    max(longest_dist[child][exp - 1],
                        longest_dist[par[child][exp - 1]][exp - 1]);
                shortest_dist[child][exp] =
                    min(shortest_dist[child][exp - 1],
                        shortest_dist[par[child][exp - 1]][exp - 1]);
                exp++;
            }
            depth[child] = depth[curr] + 1;
            find_depth(child);
        }
    }
}
int main() {
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(false);

    int n, k;
    cin >> n;
    memset(longest_dist, 0, sizeof(longest_dist));
    for (int i = 0; i < n; i++) {
        fill(par[i], par[i] + 20, -1);
        fill(shortest_dist[i], shortest_dist[i] + 20, 1000001);
    }

    for (int i = 0; i < n - 1; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        a--;
        b--;
        adj[a].push_back({b, c});
        adj[b].push_back({a, c});
    }
    find_depth(0);
    cin >> k;
    for (int i = 0; i < k; i++) {
        int v1, v2;
        cin >> v1 >> v2;
        v1--;
        v2--;
        if (depth[v1] < depth[v2])
            swap(v1, v2);
        ll shortest = 1 << 20;
        ll longest = 0;
        if (depth[v1] > depth[v2]) {
            int diff = depth[v1] - depth[v2];
            while (diff > 0) {
                for (int i = 19; i >= 0; i--) {
                    if (diff >= (1 << i)) {
                        shortest = min(shortest, shortest_dist[v1][i]);
                        longest = max(longest, longest_dist[v1][i]);
                        diff -= (1 << i);
                        v1 = par[v1][i];
                    }
                }
            }
        }
        for (int i = 19; i >= 0; i--) {
            if (par[v1][i] != par[v2][i]) {
                shortest = min(shortest,
                               min(shortest_dist[v1][i], shortest_dist[v2][i]));
                longest =
                    max(longest, max(longest_dist[v1][i], longest_dist[v2][i]));
                v1 = par[v1][i];
                v2 = par[v2][i];
            }
        }
        if (v1 != v2) {
            shortest =
                min(shortest, min(shortest_dist[v1][0], shortest_dist[v2][0]));
            longest =
                max(longest, max(longest_dist[v1][0], longest_dist[v2][0]));
            v1 = par[v1][0];
        }
        cout << shortest << " " << longest << "\n";
    }
}