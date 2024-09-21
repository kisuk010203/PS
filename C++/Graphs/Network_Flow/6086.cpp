#include <bits/stdc++.h>
using namespace std;
#define MAXN 58
int cap[MAXN][MAXN];
int flow[MAXN][MAXN];
int parent[MAXN];
vector<int> adj[MAXN];
int decode(char item) { return (item >= 'a') ? item - 'a' + 26 : item - 'A'; }
int main() {
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    memset(cap, 0, sizeof(cap));
    memset(flow, 0, sizeof(flow));

    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        char start, end;
        int flow;
        cin >> start >> end >> flow;
        int st = decode(start), en = decode(end);
        cap[st][en] += flow;
        cap[en][st] += flow;
        adj[st].push_back(en);
        adj[en].push_back(st);
    }
    int ans = 0;
    while (1) {
        queue<int> q;
        q.push(0);
        fill(parent, parent + MAXN, -1);
        while (!q.empty()) {
            int curr = q.front();
            q.pop();
            for (int next : adj[curr]) {
                if (cap[curr][next] > flow[curr][next] && parent[next] == -1) {
                    q.push(next);
                    parent[next] = curr;
                    if (next == 25)
                        break;
                }
            }
        }
        if (parent[25] == -1)
            break;
        int flow_c = INT_MAX;
        for (int i = 25; i != 0; i = parent[i]) {
            flow_c = min(flow_c, cap[parent[i]][i] - flow[parent[i]][i]);
        }
        for (int i = 25; i != 0; i = parent[i]) {
            flow[parent[i]][i] += flow_c;
            flow[i][parent[i]] -= flow_c;
        }
        ans += flow_c;
    }
    cout << ans << "\n";
}