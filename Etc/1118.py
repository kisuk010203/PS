#Silver 2 Exercises

#1182
# import sys
# n, s = map(int, sys.stdin.readline().split())
# seq = list(map(int, sys.stdin.readline().split()))
# def findseq(start, target):
#     if start == len(seq):
#         return int(target==0)
#     return findseq(start+1, target) + findseq(start+1, target-seq[start])
# cnt = findseq(0, s)
# if s==0 :
#     cnt -= 1
# print(cnt)

#1138
# import sys
# n = int(sys.stdin.readline())
# left = list(map(int, sys.stdin.readline().split()))
# pos = [-1]*n
# minpos = 0
# for i in range(n):
#     while pos[minpos] != -1:
#         minpos += 1
#     cnt=0
#     start = minpos
#     while cnt<left[i]:
#         if pos[start] == -1:
#             cnt += 1
#             start += 1
#         else:
#             start += 1
#     while pos[start] != -1:
#         start += 1
#     pos[start] = i+1
# for item in pos:
#     print(item, end = " ")

#1254
# import sys
# def isPalindrome(s):
#     l = len(s)
#     for i in range(len(s)//2):
#         if s[i] != s[l-i-1]:
#             return False
#     return True
# given = sys.stdin.readline().strip()
# add = given[::-1]
# minnum = len(add)
# for _ in range(len(given)):
#     add = add[1:]
#     if isPalindrome(given+add):
#         minnum = len(add)
# print(minnum+len(given))

#1541
# import sys
# s = sys.stdin.readline().strip()
# idx, ans, flag = 0, 0, True
# while idx < len(s):
#     temp = 0
#     while  idx < len(s) and s[idx] not in ('-', '+'):
#         temp = 10*temp + int(s[idx])
#         idx += 1
#     if flag:
#         ans += temp
#     else:
#         ans -= temp
#     if idx<len(s)-1 and s[idx] == '-':
#         flag = False
#     idx += 1
# print(ans)

#9020
# import sys
# isPrime = [True]*10000
# for i in range(2, 10000):
#     if isPrime[i]:
#         for j in range(2*i, 10000, i):
#             isPrime[j] = False
# primelist = list(item for item in range(2,10000) if isPrime[item])
# t = int(sys.stdin.readline())
# for _ in range(t):
#     n = int(sys.stdin.readline())
#     idx, p, q = 0, 0, 0
#     while primelist[idx] <= n//2:
#         if n-primelist[idx] in primelist:
#             p, q = primelist[idx], n-primelist[idx]
#         idx += 1
#     print(p, q)

#1912
# import sys
# n = int(sys.stdin.readline())
# seq = list(map(int, sys.stdin.readline().split()))
# dp = [-1001]*n
# dp[n-1] = seq[n-1]
# for item in range(n-2, -1, -1):
#     dp[item] = max(dp[item+1], 0) + seq[item]
# ans = -1001
# for item in dp:
#     if item>ans:
#         ans = item
# print(ans)


# n = int(sys.stdin.readline())
# talk = []
# cnt, endtime = 0, 0
# for _ in range(n):
#     talk.append(tuple(map(int, sys.stdin.readline().split())))
# talk.sort(key = lambda x : x[1])
# for item in talk:
#   if item[0] >= endtime:
#     cnt += 1
#     endtime = item[1]
# print(cnt)

# import sys
# n, m = map(int, sys.stdin.readline().split())
# ls = list(map(int, sys.stdin.readline().split()))
# seqdict = {}
# ls.sort()
# cnt = 0
# seqdict[0] = ls[0]
# prev = [ls[0]]*m
# seq = [0]*m
# for item in ls:
#   if seqdict[cnt] != item:
#     cnt += 1
#     seqdict[cnt] = item
# def dfs(idx):
#   if idx == m:
#     for item1, item2 in zip(prev, seq):
#       if item1 != item2:
#         break
#     else:
#       return
#     for i in range(m):
#       prev[i] = seqdict[seq[i]]
#       print(prev[i], end = " ")
#     print()
#   elif idx == 0:
#     for i in range(cnt+1):
#       seq[idx] = i
#       dfs(1)
#   else:
#     for i in range(seq[idx-1],cnt+1):
#       seq[idx] = i
#       dfs(idx+1)
# dfs(0)

# import sys
# N, M = map(int, sys.stdin.readline().split())
# ls = []
# alph, empt = [set() for _ in range(N)], set()
# cnt = 0
# flag = True
# for _ in range(M):
#     ls.append(sys.stdin.readline())
# sorted(ls)
# for idx in range(N):
#     for item in ls:
#         alph[idx].add(item[idx])
# for alphSet in alph :
#     cnt += len(alphSet)
#     empt = empt.union(alphSet)
# for i in range(len(ls)-1):
#     if(ls[i] == ls[i+1]):
#         flag = False
# if cnt != len(empt):
#     flag = False
# else:
#   res = 1
#   for alphSet in alph :
#     res *= len(alphSet)
#   if(res != M):
#     flag = False
#   else:
#     print("YES")
#     for alphSet in alph:
#               for item in sorted(alphSet):
#                   print(item, end = "")
#               print()
# if(flag == False):
#   print("NO")

ls = [1,2,3,4,5]
print(*ls, end = "")
print("!")
