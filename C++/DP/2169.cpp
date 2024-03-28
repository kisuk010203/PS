#include <bits/stdc++.h>
using namespace std;
#define MAX 1010
int N, M;
int board[MAX][MAX];
int direc_dp[MAX][3];
int ansdp[MAX];
int main(int argc, char const* argv[]) {
    memset(direc_dp, 0, sizeof(direc_dp));
    memset(ansdp, 0, sizeof(ansdp));
    cin >> N >> M;
    for (int i = 0; i < N; i++)
        for (int j = 0; j < M; j++)
            cin >> board[i][j];
    ansdp[0] = board[0][0];
    for (int i = 1; i < M; i++)  // 0 row
        ansdp[i] = ansdp[i - 1] + board[0][i];
    if (N == 1) {
        cout << ansdp[M - 1];
        return 0;
    }
    for (int r = 1; r < N; r++) {
        for (int c = 0; c < M; c++)
            direc_dp[c][0] = ansdp[c] + board[r][c];
        direc_dp[0][1] = direc_dp[0][0];
        direc_dp[M - 1][2] = direc_dp[M - 1][0];
        for (int c = 1; c < M; c++)
            direc_dp[c][1] = max(direc_dp[c - 1][1], ansdp[c]) + board[r][c];
        for (int c = M - 2; c >= 0; c--)
            direc_dp[c][2] = max(direc_dp[c + 1][2], ansdp[c]) + board[r][c];
        for (int c = 0; c < M; c++)
            ansdp[c] = max(direc_dp[c][0], max(direc_dp[c][1], direc_dp[c][2]));
    }
    cout << max(direc_dp[M - 1][0],
                max(direc_dp[M - 1][1], direc_dp[M - 1][2]));
    return 0;
}
