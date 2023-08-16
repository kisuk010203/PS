for i in range(1, m):
    b_dp[0][i] = b_dp[0][i-1] + seqb[i]
for i in range(1, m):
    for j in range(i, m):
        b_dp[i][j] = b_dp[i-1][j] - seqb[i-1]