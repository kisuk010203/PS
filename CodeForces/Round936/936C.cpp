#include <bits/stdc++.h>
using namespace std;
int n, k;
int cut_count;
vector<vector<int>> adj;
int count_descendants(int x, int node, int parent) {
    int result = 1;
    for (int child : adj[node]) {
        if (child == parent)
            continue;
        result += count_descendants(x, child, node);
    }
    if (result >= x) {
        cut_count++;
        return 0;
    }
    return result;
}
bool try_if_x_possible(int x) {
    cut_count = 0;
    count_descendants(x, 0, -1);
    // cout << x << " " << cut_count << "\n";
    return cut_count >= k + 1;
}
int main() {
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(false);
    int T;
    cin >> T;
    while (T--) {
        cin >> n >> k;
        adj.clear();
        adj.resize(n);
        for (int i = 0; i < n - 1; i++) {
            int u, v;
            cin >> u >> v;
            u--;
            v--;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        int left = 1, right = n;
        while (left < right) {
            int mid = (left + right) / 2;
            bool ret = try_if_x_possible(mid);
            if (ret) {
                left = mid + 1;
            } else
                right = mid;
        }
        cout << left - 1 << "\n";
    }
}