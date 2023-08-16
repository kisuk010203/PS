#include <bits/stdc++.h>
using namespace std;
#define MAX 501
typedef long long ll;
int N, M;
ll dp[MAX][MAX][4];
ll board[MAX][MAX];
int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};
ll dfs(int row, int col, int mode){
    //cout <<row << ' ' << col << ' ' << mode << '\n';
    if(dp[row][col][mode] != -1) return dp[row][col][mode];
    int nrow = row+dx[mode];
    int ncol = col+dy[mode];
    if(nrow < 0 || nrow>=N || ncol<0 || ncol>=M) return dp[row][col][mode] = 0;
    if(board[row][col] >= board[nrow][ncol]) return dp[row][col][mode] = 0;
    ll getnum = 0;
    for(int j=0; j<4; j++) getnum += dfs(nrow, ncol, j);
    return dp[row][col][mode] = getnum;
}
int main(int argc, char const *argv[]){
    cin >> N >> M;
    for(int i=0; i<N; i++)
        for (int j = 0; j < M; j++)
            cin >> board[i][j];
    memset(dp, -1, sizeof(dp));
    dp[0][0][0] = 1;
    ll ans = 0;
    for(int i=0; i<4; i++) ans += dfs(N-1, M-1, i);
    // for(int k=0; k<4; k++){
    //     cout << "Mode : " << k << '\n';
    //     for(int i=0; i<N; i++){
    //         for (int j = 0; j < M; j++)
    //             cout << dp[i][j][k] << ' ';
    //         cout << endl;
    //     }
    // }
    cout << ans;
    return 0;
}
