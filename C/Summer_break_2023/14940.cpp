#include <bits/stdc++.h>
using namespace std;
#define MAX 1000
int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};
typedef pair<int, int> p;
int n, m;
int board[MAX][MAX];
int answer_board[MAX][MAX];
bool is_valid(int i, int j, int idx) {
    return (i + dx[idx] >= 0) && (i + dx[idx] < n) && (j + dy[idx] >= 0) &&
           (j + dy[idx] < m);
}
bool needs_search(int i, int j, int idx) {
    return answer_board[i + dx[idx]][j + dy[idx]] == 0 &&
           board[i + dx[idx]][j + dy[idx]] == 1;
}
int main(int argc, char const *argv[]) {

    cin >> n >> m;
    p start;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> board[i][j];
            if (board[i][j] == 2) {
                start = {i, j};
            }
        }
    }
    memset(answer_board, 0, sizeof(answer_board));

    queue<p> bfs_queue;
    bfs_queue.push(start);
    while (!bfs_queue.empty()) {
        p current = bfs_queue.front();
        bfs_queue.pop();
        for (int idx = 0; idx < 4; idx++) {
            if (is_valid(current.first, current.second, idx) &&
                needs_search(current.first, current.second, idx)) {
                bfs_queue.push(
                    {current.first + dx[idx], current.second + dy[idx]});
                answer_board[current.first + dx[idx]]
                            [current.second + dy[idx]] =
                                answer_board[current.first][current.second] + 1;
            }
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (board[i][j] == 1 && answer_board[i][j] == 0)
                answer_board[i][j] = -1;
            printf("%d ", answer_board[i][j]);
        }
        printf("\n");
    }
    return 0;
}
