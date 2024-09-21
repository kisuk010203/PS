#include <bits/stdc++.h>
using namespace std;
#define MAXN 300300
vector<pair<int, int>> adj[MAXN];
vector<int> dist[MAXN];
int level[MAXN];
int n, m, s, e;
int main() {
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    cin >> n >> m >> s >> e;
    for (int i = 0; i < m; i++) {
        int x, y, w;
        cin >> x >> y >> w;
        adj[x].push_back({y, w});
        adj[y].push_back({x, w});
    }
    deque<int> dq;
    dq.push_back(s);
    dist[s].push_back(0);
    while (!dq.empty()) {
        int cur = dq.front();
        dq.pop_front();
        for (pair<int, int> nxt : adj[cur]) {
            if (dist[nxt.first].empty() && nxt.second == 0) {
                dist[nxt.first].push_back(0);
                dq.push_back(nxt.first);
            }
        }
    } // find all the zeros

    for (int i = 1; i <= n; i++) {
        if (!dist[i].empty()) {
            dq.push_back(i);
            level[i] = 0;
        }
    } // dq contains all the zeros
    dq.push_back(-1);

    while (!dq.empty()) {
        deque<int> temp;

        while (dq.front() != -1) {
            temp.push_front(dq.front());
            dq.pop_front();
        }
        dq.pop_front();

        int zero_cnt = 0;
        for (int cur : temp) {
            for (pair<int, int> nxt : adj[cur]) {
                if (dist[nxt.first].empty() && nxt.second == 0) {
                    dist[nxt.first].push_back(cur);
                    dist[nxt.first].push_back(nxt.second);
                    dq.push_back(nxt.first);
                    zero_cnt++;
                }
            }
        }
        if (zero_cnt)
            dq.push_back(-1);

        int one_cnt = 0;
        for (int cur : temp) {
            for (pair<int, int> nxt : adj[cur]) {
                if (dist[nxt.first].empty() && nxt.second == 1) {
                    dist[nxt.first].push_back(cur);
                    dist[nxt.first].push_back(nxt.second);
                    dq.push_back(nxt.first);
                    one_cnt++;
                }
            }
        }
        if (one_cnt)
            dq.push_back(-1);
    }

    if (dist[e].size() == 1)
        cout << 0;
    else {
        vector<int> temp;
        while (dist[e][0] != 0) {
            temp.push_back(dist[e][1]);
            e = dist[e][0];
        }
        for (int i = temp.size() - 1; i >= 0; i--) {
            cout << temp[i];
        }
    }
}