
# n = int(sys.stdin.readline())
# for _ in range(n):
#     flag = True
#     temp = sys.stdin.readline()
#     while len(temp)>=3:
#         if temp[0] == '0':
#             if temp[1] == '0':
#                 flag = False
#                 break
#             temp = temp[2:]
#             continue
#         elif temp[1] == '1' or temp[2] == '1':
#             flag = False
#             break
#         else:
#             cnt , cnt2 = 3, 0
#             try:
#                 while temp[cnt] == '0':
#                     cnt += 1
#                 cnt2 = cnt
#             except:
#                 flag = False
#                 break
#             try:
#                 while temp[cnt] == '1':
#                     cnt+=1
#             except:
#                 flag = True
#                 break
#             if cnt == len(temp) - 1:
#                 flag = False
#                 break
#             elif temp[cnt+1] == '0' and cnt2 < cnt - 1:
#                 temp = temp[cnt-1:]
#             else:
#                 temp = temp[cnt:]
#     else:
#         if temp not in ("", "01"):
#             flag = False
#     print("YES" if flag else "NO")


# import sys
# t = int(sys.stdin.readline())
# for _ in range(t):
#     n, k = map(int, sys.stdin.readline().split())
#     arr = [[] for _ in range(n)]
#     time = list(map(int, sys.stdin.readline().split()))
#     dp = [-1]*n
#     for _ in range(k):
#         a, b = map(int, sys.stdin.readline().split())
#         arr[b-1].append(a-1)
#     target = int(sys.stdin.readline())
#     target-=1
#     def dfs(end):
#         if dp[end] != -1:
#             return dp[end]
#         if not arr[end]:
#             dp[end] = time[end]
#             return time[end]
#         ls = []
#         for item in arr[end]:
#             ls.append(dfs(item))
#         dp[end] = time[end] + max(ls)
#         return dp[end]
#     print(dfs(target))


# import sys
# l, c = map(int, sys.stdin.readline().split())
# given = sys.stdin.readline().rstrip()
# alph = given.split()
# alph.sort()
# def backtracking(idx, nv, nc, seq):
    
#     if idx == l:
#         if nv>=1 and nc>=2:
#             print(seq)
#             return
#     else:
#         if idx == 0:
#             for i in range(idx, c-l+idx+1):
#                 if alph[i] in "aeiou":
#                     backtracking(idx+1, nv+1, nc, seq+alph[i])
#                 else:
#                     backtracking(idx+1, nv, nc+1, seq+alph[i])
#         for i in range(idx, c-l+idx+1):
#             if alph[i] > seq[idx-1]:
#                 if alph[i] in "aeiou":
#                     backtracking(idx+1, nv+1, nc, seq+alph[i])
#                 else:
#                     backtracking(idx+1, nv, nc+1, seq+alph[i])
# backtracking(0, 0, 0, "")
    
# import sys
# n = int(sys.stdin.readline())
# ls = []
# for _ in range(n-1):
#     ls.append(int(sys.stdin.readline().split()[0]))
# ls += list(map(int, sys.stdin.readline().split()))
# print(ls)
# def backtracking(matlist, val, lenList):
#     if lenList == 3:
#         return val + matlist[0]*matlist[1]*matlist[2]
#     given = []
#     for i in range(1,lenList-1):
#         given.append(backtracking(matlist[:i]+matlist[i+1:], val+matlist[i-1]*matlist[i]*matlist[i+1], lenList-1))
#     return max(given)
# print(backtracking(ls, 0, len(ls)))
        
    

        