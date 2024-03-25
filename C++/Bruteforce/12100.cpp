#include <bits/stdc++.h>
using namespace std;
int board[20][20];
int changed[20][20];
int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};
int max_val = 0;
int n;
bool is_possible(int r, int c, int move) {
    int next_r = r + dx[move];
    int next_c = c + dy[move];
    return (next_r >= 0 && next_r < n && next_c >= 0 && next_c < n);
}
void do_move(int i, int j, int move) {
    if (board[i][j] == 0)
        return;
    while (is_possible(i, j, move)) {
        if (board[i + dx[move]][j + dy[move]] == 0) {
            board[i + dx[move]][j + dy[move]] = board[i][j];
            board[i][j] = 0;

        } else if (board[i + dx[move]][j + dy[move]] == board[i][j]) {
            if (changed[i + dx[move]][j + dy[move]] == 1 || changed[i][j] == 1)
                return;
            board[i + dx[move]][j + dy[move]] *= 2;
            board[i][j] = 0;
            changed[i][j] = 0;
            changed[i + dx[move]][j + dy[move]] = 1;
        } else
            return;
        i = i + dx[move];
        j = j + dy[move];
    }
}
void backtracking(int cnt) {
    if (cnt == 5) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                max_val = max(max_val, board[i][j]);
            }
        }
        return;
    }

    int temp[20][20];
    copy(&board[0][0], &board[0][0] + 20 * 20, &temp[0][0]);
    for (int move = 0; move < 4; move++) {
        memset(changed, 0, sizeof(changed));
        if (move % 2 == 1) {
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < n; j++) {
                    do_move(i, j, move);
                }
            }
        } else {
            for (int i = n - 1; i >= 0; i--) {
                for (int j = n - 1; j >= 0; j--) {
                    do_move(i, j, move);
                }
            }
        }
        backtracking(cnt + 1);
        copy(&temp[0][0], &temp[0][0] + 20 * 20, &board[0][0]);
    }
}
int main() {
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(false);
    cin >> n;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> board[i][j];
        }
    }
    backtracking(0);
    cout << max_val << "\n";
}