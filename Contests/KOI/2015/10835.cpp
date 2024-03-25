#include <bits/stdc++.h>
using namespace std;
int N;
int left_card[2001];
int right_card[2001];
int dp[2001][2001];

int main(int argc, char const* argv[]) {
    cin >> N;
    memset(dp, 0, sizeof(dp));
    for (int i = 0; i < N; i++)
        cin >> left_card[N - i];
    for (int i = 0; i < N; i++)
        cin >> right_card[N - i];
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - 1]);
            if (left_card[i] > right_card[j])
                dp[i][j] = max(dp[i][j - 1] + right_card[j], dp[i][j]);
        }
    }
    cout << dp[N][N];
    return 0;
}
