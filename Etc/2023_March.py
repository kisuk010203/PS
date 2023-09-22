#1208

# import sys
# from collections import defaultdict
# input = sys.stdin.readline
# n, s = map(int, input().split())
# seq = list(map(int, input().split()))
# a_dict = defaultdict(int)
# b_dict = defaultdict(int)
# ans = 0
# mid = n//2
# def a_dfs(start, curr):
#     if start == mid:
#         a_dict[curr] += 1
#         return
#     a_dfs(start+1, curr)
#     a_dfs(start+1, curr+seq[start])
# def b_dfs(start, curr):
#     if start == n:
#         b_dict[curr] += 1
#         return
#     b_dfs(start+1, curr)
#     b_dfs(start+1, curr+seq[start])
# if n == 1 :
#     print((int)(s == seq[0]))
# else:
#     a_dfs(0, 0)
#     b_dfs(mid,0)

#     for keys in a_dict:
#         ans += a_dict[keys]*b_dict[s-keys]
#     if s == 0:
#         ans -= 1
#     print(ans)

#2143
import sys
from collections import defaultdict
input = sys.stdin.readline
t = int(input())
n = int(input())
seqa = list(map(int, input().split()))
m = int(input())
seqb = list(map(int, input().split()))
a_dict = defaultdict(int)
b_dict = defaultdict(int)
a_dp = [[0 for _ in range(n)] for _ in range(n)]
b_dp = [[0 for _ in range(m)] for _ in range(m)]
ans = 0
a_dp[0][0] = seqa[0]
a_dict[seqa[0]] += 1
b_dict[seqb[0]] += 1
b_dp[0][0] = seqb[0]
for i in range(1, n):
    a_dp[0][i] = a_dp[0][i-1] + seqa[i]
    a_dict[a_dp[0][i]] += 1
for i in range(1, n):
    for j in range(i, n):
        a_dp[i][j] = a_dp[i-1][j] - seqa[i-1]
        a_dict[a_dp[i][j]] += 1
for i in range(1, m):
    b_dp[0][i] = b_dp[0][i-1] + seqb[i]
    b_dict[b_dp[0][i]] += 1
for i in range(1, m):
    for j in range(i, m):
        b_dp[i][j] = b_dp[i-1][j] - seqb[i-1]
        b_dict[b_dp[i][j]] += 1

for keys in a_dict:
    ans += a_dict[keys]*b_dict[t-keys]
print(ans)
