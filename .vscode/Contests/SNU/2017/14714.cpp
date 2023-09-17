#include <bits/stdc++.h>
using namespace std;
#define MAX 500
#define INF 25000000
int n, da, db;
int dist[MAX][MAX];

bool update(int a, int b, int new_val) {
    a += n;
    b += n;
    a %= n;
    b %= n;
    if (dist[a][b] <= new_val)
        return false;
    dist[a][b] = new_val;
    return true;
}
int main() {
    int a, b;
    cin >> n >> a >> b >> da >> db;
    int dx[4] = {-da, da, -da, da};
    int dy[4] = {db, db, -db, -db};
    a--;
    b--;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            dist[i][j] = INF;
        }
    }
    dist[a][b] = 0;
    queue<pair<int, int>> bfs_Q;
    bfs_Q.push({a, b});
    while (!bfs_Q.empty()) {
        pair<int, int> curr = bfs_Q.front();
        int a = curr.first;
        int b = curr.second;
        bfs_Q.pop();
        for (int i = 0; i < 4; i++) {
            int are_same = a + dx[i] - b;
            are_same = (are_same + 2 * n) % n;
            if (are_same == 0) {
                int idx = (a + dx[i] + n) % n;
                dist[idx][idx] = min(dist[idx][idx], dist[a][b] + 1);
            }
            bool ans = update(a + dx[i], b + dy[i], dist[a][b] + 2);
            if (ans)
                bfs_Q.push({(a + dx[i] + n) % n, (b + dy[i] + n) % n});
        }
    }
    int ans = INF;
    for (int i = 0; i < n; i++) {
        ans = min(ans, dist[i][i]);
    }
    if (ans == INF) {
        cout << "Evil Galazy";
    } else
        cout << ans;
}
