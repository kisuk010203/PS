#include <bits/stdc++.h>
using namespace std;

#define ANS_INF 3000000

int N, W;
int enemies[10000][2];
int plain_enemies[10000][2];

int get_result() {
    // for (int j = 0; j < 2; j++) {
    //     for (int i = 0; i < N; i++) {
    //         cout << enemies[i][j] << " ";
    //     } cout << "\n";
    // }
    int dp[N][3];
    dp[0][1] = dp[0][2] = 1;
    dp[0][0] = (enemies[0][0] + enemies[0][1] > W ? 2 : 1);

    for (int i = 1 ; i < N; i++) {
        dp[i][1] = 1 + dp[i - 1][0];
        if (enemies[i][1] + enemies[i - 1][1] <= W)
            dp[i][1] = min(dp[i][1], dp[i - 1][2] + 1);
        
        dp[i][2] = 1 + dp[i - 1][0];
        if (enemies[i][0] + enemies[i - 1][0] <= W)
            dp[i][2] = min(dp[i][2], dp[i - 1][1] + 1);

        dp[i][0] = ANS_INF;
        dp[i][0] = min(dp[i][0], dp[i][1] + 1);
        dp[i][0] = min(dp[i][0], dp[i][2] + 1);
        if (enemies[i][0] + enemies[i][1] <= W) {
            dp[i][0] = min(dp[i][0], dp[i-1][0] + 1);
        } else {
            dp[i][0] = min(dp[i][0], dp[i - 1][0] + 2);
        }
        int without_two = (i == 1) ? 2 : dp[i - 2][0] + 2;
        if (enemies[i][0] + enemies[i - 1][0] > W) without_two++;
        if (enemies[i][1] + enemies[i - 1][1] > W) without_two++;
        dp[i][0] = min(dp[i][0], without_two);
    }
    // for (int j = 0; j < 3; j++) {
    //     for (int i = 0; i < N; i++) {
    //         cout << dp[i][j] << " ";
    //     } cout << "\n";
    // }   
    return dp[N - 1][0];
}

int modify_and_get_result(unsigned int row_bitmask) {
    // cout << row_bitmask << ": \n";
    for (int bit = 0; bit < 2; bit++)
        if (row_bitmask & (1 << bit)) {
            if (enemies[0][bit] + enemies[N - 1][bit] > W) 
                return ANS_INF;
            enemies[0][bit] = enemies[N - 1][bit] = W;
        }
    int offset = __builtin_popcount(row_bitmask);
    int res = get_result() - offset;

    // cout << res + offset << "-" << offset << "!!\n";

    enemies[0][0] = plain_enemies[0][0];
    enemies[0][1] = plain_enemies[0][1];
    enemies[N - 1][0] = plain_enemies[N - 1][0];
    enemies[N - 1][1] = plain_enemies[N - 1][1];
    
    
    return res;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int T; cin >> T;
    while (T--) {
        cin >> N >> W;
        for (int j = 0; j < 2; j++)
            for (int i = 0; i < N; i++){
                cin >> plain_enemies[i][j];
                enemies[i][j] = plain_enemies[i][j];
            }
        
        if (N == 1) {
            cout << get_result() << "\n";
            continue;
        }
        int ans = ANS_INF;
        for (unsigned int row_bitmask = 0; row_bitmask < 4; row_bitmask++) {
            ans = min(ans, modify_and_get_result(row_bitmask));
        }
        cout << ans << "\n";
    }
    
}