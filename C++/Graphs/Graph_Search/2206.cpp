#include <bits/stdc++.h>
using namespace std;

typedef tuple<int, int, int, int> tue;
int n, m;
int x_next[4] = {-1, 1, 0, 0};
int y_next[4] = {0, 0, -1, 1};
int arr[1004][1004];
int visited[1004][1004][2];

int in_bound(int r, int c) {
    return ((r >= 0 && r < n) && (c >= 0 && c < m));
}
int main() {
    memset(visited, 0, sizeof(visited));
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        char temp[1004];
        cin >> temp;
        for (int j = 0; j < m; j++) {
            arr[i][j] = temp[j] - '0';
        }
    }

    queue<tue> que;
    que.push(make_tuple(0, 0, 0, 1));
    visited[0][0][0] = 1;
    visited[0][0][1] = 1;

    while (!que.empty()) {
        tue temp = que.front();
        int r = get<0>(temp);
        int c = get<1>(temp);
        int used = get<2>(temp);
        int dist = get<3>(temp);
        que.pop();
        if (r == n - 1 && c == m - 1) {
            cout << dist;
            return 0;
        }
        for (int i = 0; i < 4; i++) {
            int new_r = r + x_next[i];
            int new_c = c + y_next[i];
            if (in_bound(new_r, new_c) && visited[new_r][new_c][used] == 0) {
                if (used == 0) {
                    visited[new_r][new_c][used] = 1;
                    que.push(
                        make_tuple(new_r, new_c, arr[new_r][new_c], dist + 1));
                } else if (arr[new_r][new_c] == 0) {
                    visited[new_r][new_c][used] = 1;
                    que.push(make_tuple(new_r, new_c, 1, dist + 1));
                }
            }
        }
    }
    cout << -1;
}
