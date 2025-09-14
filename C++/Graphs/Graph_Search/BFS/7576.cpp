#include<bits/stdc++.h>
using namespace std;
#define INF 100000000
int M, N;

pair<int, int> diff[4] = {{-1, 0}, {1, 0}, {0, 1}, {0, -1}};
bool outOfBounds(int r, int c) {
    return r < 0 || r >= N || c < 0 || c >= M;
}
bool unAvailable(int r, int c, vector<vector<int>> &map, vector<vector<int>> &dist) {
    return outOfBounds(r, c) || map[r][c] == -1 || dist[r][c] != INF;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> M >> N;
    vector<vector<int>> map(N, vector<int>(M, 0));
    vector<vector<int>> dist(N, vector<int>(M, 0));
    queue<pair<int, int>> q;

    for (int i = 0; i < N; i++)
        for (int j = 0; j < M; j++) {
            cin >> map[i][j];
            dist[i][j] = INF;
            if (map[i][j] == 1) {
                q.push({i, j});
                dist[i][j] = 0;
            }
        }
    
    while(!q.empty()) {
        auto [r, c] = q.front();
        q.pop();
        for (auto &[dr, dc] : diff) {
            if (!unAvailable(r + dr, c + dc, map, dist)) {
                dist[r + dr][c + dc] = dist[r][c] + 1;
                q.push({r + dr, c + dc});
            }
        }
    }

    int maxLen = 0;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            if (map[i][j] != -1 && dist[i][j] == INF) {
                cout << "-1\n";
                exit(0);
            } else if (dist[i][j] != INF) {
                maxLen = max(maxLen, dist[i][j]);
            }

        }
    }
    cout << maxLen << "\n";

}