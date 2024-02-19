import sys

n = int(sys.stdin.readline())
s = set()
for _ in range(n):
    a, b = map(int, sys.stdin.readline().split())
    s.add((a - 1, b - 1))
dp = [[0 for _ in range(501)] for _ in range(501)]
for i in range(998, -1, -1):
    for j in range(0, i + 1):
        if j >= 500 or i - j >= 500:
            continue
        dp[j][i-j] = max(dp[j+1][i-j], dp[j][i-j+1])
        if (j, i-j) in s:
            dp[j][i-j] += 1
print(n - dp[0][0])
