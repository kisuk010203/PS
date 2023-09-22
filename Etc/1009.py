# seqDict = {0:1}
# n, p, q = map(int, input().split())
# def setDp(n):
#     if n in seqDict:
#         return seqDict[n]
#     if n//p in seqDict and n//q in seqDict:
#         seqDict[n] = seqDict[n//p] + seqDict[n//q]
#         return seqDict[n]
#     k= setDp(n//p) + setDp(n//q)
#     seqDict[n] = k
#     return k
# setDp(n)
# print(seqDict[n])

# s = []
# s.append("###...#.###.###.#.#.###.###.###.###.###")
# s.append("#.#...#...#...#.#.#.#...#.....#.#.#.#.#")
# s.append("#.#...#.###.###.###.###.###...#.###.###")
# s.append("#.#...#.#.....#...#...#.#.#...#.#.#...#")
# s.append("###...#.###.###...#.###.###...#.###.###")
# d = {}
# ans = 0.0
# for i in range(10):
#     temp = ""
#     for j in range(5):
#         temp += s[j][4*i:4*i+3]
#     d[i] = temp
# N = int(input())
# inLight = ["" for _ in range(N)]
# for _ in range(5):
#     s = input()
#     for i in range(N):
#         inLight[i] += s[4*i : 4*i+3]
# def inside(s1, s2):
#     for i in range(len(s1)):
#         if s1[i] == '#' and s2[i] == '.':
#             return False
#     return True
# def possible(s, n):
#     sum, cnt = 0, 0
#     for i in range(10):
#         if inside(s, d[i]):
#             sum += i
#             cnt += 1
#     return pow(10, N-n) * sum / cnt
# try:
#     for i in range(N):
#         ans += possible(inLight[i], i+1)
#     print(ans)
# except:
#     print(-1)

# N = int(input())
# ls = []
# for _ in range(N):
#     ls.append(list(map(int, input().split())))
# ls = sorted(ls, key = lambda x : x[1])[::-1]
# start = ls[0][1]
# for i in ls:
#     start = min(start, i[1]) - i[0]
# if start<0:
#     print(-1)
# else:
#     print(start)

# from string import ascii_uppercase

# m, n = map(int, input().split())
# d = dict()
# for item in ascii_uppercase:
#     d[item] = 0
# ls = []
# for _ in range(m):
#     ls.append(input()*2)
# ls = ls + ls
# for i in range(2*m):
#     for j in range(2*n):
#         d[ls[i][j]] += (i+1)*(j+1)*(2*m-i)*(2*n-j)
# for i in d:
#     print(d[i])

# import sys
# sys.setrecursionlimit(10 ** 6)
# n, m = map(int, input().split())
# ls = [set([i]) for i in range(n)]
# for _ in range(m):
#     a, b = map(int, input().split())
#     ls[b-1].add(a-1)
# searched = [False] * n
# def dfs(start):
#     if searched[start]:
#         return
#     searched[start] = True
#     for item in ls[start]:
#         dfs(item)
#         ls[start] = ls[start].union(ls[item])
# for i in range(n):
#     if not searched[i]:
#         dfs(i)
# ma = max(list(len(item) for item in ls))
# for i in range(n):
#     if len(ls[i]) == ma:
#         print(i+1, end = " ")

# import sys
# from collections import defaultdict, deque

# n, m = map(int, sys.stdin.readline().split())
# edge = defaultdict(list)
# for _ in range(m):
#     a, b = map(int, sys.stdin.readline().split())
#     edge[b].append(a)
# def bfs(start):
#     cnt = 1
#     isSearched = [False]*(n+1)
#     isSearched[start] = 1
#     dq = deque([start])
#     while dq:
#         u = dq.popleft()
#         for v in edge[u]:
#             if not isSearched[v]:
#                 cnt += 1
#                 dq.append(v)
#                 isSearched[v] = True

#     return cnt
# ans, ma = [], 0
# for i in range(1, n+1):
#     cnt = bfs(i)
#     if cnt > ma:
#         ma = cnt
#         ans=[[i, cnt]]
#     elif cnt == ma:
#         ans.append([i, cnt])

# for i, cnt in ans:
#     print(i, end = " ")

# import sys
# dp = dict()
# for i in range(10):
#     dp[i] = str(i)
# n = int(sys.stdin.readline())
# def setdp(n):
#     if n in dp:
#         return dp[n]
#     else:
#         t = setdp(n-1)
#         for pos in range(len(t)-1, -1, -1):
#             if (pos >0 and int(t[pos]) < int(t[pos-1]) - 1) or (pos == 0 and t[0] != "9"):
#                 s = t[:pos] + str(int(t[pos])+1)
#                 for j in range(len(t)-pos-2, -1, -1):
#                     s += str(j)
#                 dp[n] = s
#                 return s

#         s = ""
#         for i in range(len(t),-1,-1):
#             s+= str(i)
#         dp[n] = s
#         return s

# if n > 1022:
#     print(-1)
# else:
#     setdp(n)
#     print(dp[n])

# import sys
# c, n = map(int, sys.stdin.readline().split())
# d = dict()
# dp = dict()
# dp[0] = 0
# for _ in range(n):
#     price, people = map(int, sys.stdin.readline().split())
#     if price not in d or d[price] < people:
#         d[price] = people
# m = min(d.keys())
# def setdp(N):
#     if N<0:
#         return 0
#     if N in dp:
#         return dp[N]
#     s = 10**10
#     for item in d:
#         s = min(s, setdp(N-d[item]) + item)
#     dp[N] = s
#     return s
# print(setdp(c))

# d = {0:(1,0), 1:(0,1)}
# def getdp(N):
#     if N in d:
#         return d[N]
#     else:
#         d[N] = (getdp(N-1)[0] + getdp(N-2)[0], getdp(N-1)[1] + getdp(N-2)[1])
#         return d[N]
# numtest = int(input())
# for _ in range(numtest):
#     n = int(input())
#     print(getdp(n)[0], getdp(n)[1])

# class car():
#   def __init__(self, s, w, n):
#     self.speed = s
#     self.wheels = w
#     self.name = n
#   def prints(self):
#     print(self.speed)
# class truck(car):
#     def __init__(self, s, w, n, c):
#        super().__init__(s, w, n)
#        self.capacity = c
# t = truck(4, 10, "t", 6)
# car.prints(t)

# cnt = 0
# for i in range(2, 10000):
#     for j in range(2, i):
#         if i%j == 0:
#             break
#     else:
#         cnt += 1
# print(cnt)

# for a in range(1, 100, 5):
#     print(a)

# def getMod(a, b, c):
#     if b == 0:
#         return 1
#     if b%2 == 0:
#         return (getMod(a, b//2, c)**2)%c
#     return ((getMod(a, b//2, c)**2)%c * a)%c
# a, b, c = map(int , input().split())
# print(getMod(a, b, c))

# path = dict()
# def findPath(row, col):
#     if (row, col) in path:
#         return path[(row, col)]
#     path[(row, col)] = ls[row][col] + max(findPath(row+1, col), findPath(row+1, col+1))
#     return path[(row, col)]
# depth = int(input())
# ls = []
# for i in range(depth):
#     ls.append(list(map(int, input().split())))
# for col in range(depth):
#     path[(depth-1, col)] = ls[depth-1][col]
# print(findPath(0,0))

# from string import ascii_uppercase
# hashdict = {"." : -1}
# for idx, letter in enumerate(ascii_uppercase):
#     hashdict[letter] = idx
# numnode = int(input())
# tree = {}
# for _ in range(numnode):
#     node, lnode, rnode = input().split()
#     tree[hashdict[node]] = (hashdict[lnode], hashdict[rnode])

# def preorder(node):
#     if node == -1:
#         return
#     print(ascii_uppercase[node], end = "")
#     preorder(tree[node][0])
#     preorder(tree[node][1])

# def inorder(node):
#     if node == -1:
#         return
#     inorder(tree[node][0])
#     print(ascii_uppercase[node], end = "")
#     inorder(tree[node][1])

# def postorder(node):
#     if node == -1:
#         return
#     postorder(tree[node][0])
#     postorder(tree[node][1])
#     print(ascii_uppercase[node], end = "")

# preorder(0); print()
# inorder(0); print()
# postorder(0); print()

# fibodict = {0:0, 1:1}
# def gcd(n, m):
#     if m == 0 :
#         return n
#     return gcd(m, n%m)
# def setdict(n):
#     if n in fibodict:
#         return fibodict[n]
#     if n%2 == 0:
#         fibodict[n] = setdict(n//2) * ((setdict(n//2) + 2* setdict(n//2 - 1))%c)%c
#         return fibodict[n]
#     fibodict[n] = ((setdict(n//2) ** 2)%c + (setdict(n//2 + 1)**2)%c)%c
#     return fibodict[n]
# n, m = map(int, input().split())
# d = gcd(n, m)
# c = 1000000007
# print(setdict(d))

# fibodict = {0:0, 1:1}
# def setdict(n):
#     if n in fibodict:
#         return fibodict[n]
#     if n%2 == 0:
#         fibodict[n] = setdict(n//2) * ((setdict(n//2) + 2* setdict(n//2 - 1))%c)%c
#         return fibodict[n]
#     fibodict[n] = ((setdict(n//2) ** 2)%c + (setdict(n//2 + 1)**2)%c)%c
#     return fibodict[n]
# T = int(input())

# a, b = map(int, input().split())
# c = 1000000000
# print((setdict(b+2) - setdict(a+1))%c)



# T = int(input())
# for i in range(T):
#     p, c = map(int, input().split())
#     fibodict = {0:0, 1:1%c}
#     def setdict(n):
#         if n in fibodict:
#             return fibodict[n]
#         if n%2 == 0:
#             fibodict[n] = setdict(n//2) * ((setdict(n//2) + 2* setdict(n//2 - 1))%c)%c
#             return fibodict[n]
#         fibodict[n] = ((setdict(n//2) ** 2)%c + (setdict(n//2 + 1)**2)%c)%c
#         return fibodict[n]
#     print("Case #{0}: {1}".format(i+1, setdict(p)))

# n, b = map(int, input().split())
# def matmul(ls1, ls2):
#     ls3 = [[0 for _ in range(n)] for _ in range(n)]
#     for i in range(n):
#         for j in range(n):
#             for k in range(n):
#                 ls3[i][j] = (ls3[i][j] + ls1[i][k] * ls2[k][j] %1000)%1000
#     return ls3

# mat = []
# unit = [[0]*i + [1] + [0]*(n-i-1) for i in range(n)]
# for _ in range(n):
#     mat.append(list(map(int, input().split())))
# matdict = {0:unit, 1:mat}

# def setmatdict(m):
#     if m in matdict:
#         return matdict[m]
#     if m%2 == 0:
#         matdict[m] = matmul(setmatdict(m//2), setmatdict(m//2))
#         return matdict[m]
#     matdict[m] = matmul(setmatdict(m//2), setmatdict(m//2 + 1))
#     return matdict[m]

# ans = setmatdict(b)
# for item in ans:
#     for elem in item:
#         print(elem%1000 , end = " ")
#     print()

# n = int(input())
# seq = list(map(int, input().split()))
# dp = [1 for _ in range(n)]
# def setdp(m):
#     if dp[m] > 1 :
#         return dp[m]
#     min = 1
#     for i in range(m+1, n):
#         if seq[i] > seq[m] and 1 + setdp(i) > min:
#             min = 1 + setdp(i)
#     dp[m] = min
#     return dp[m]
# print(max(setdp(i) for i in range(n)))

# import sys
# sys.setrecursionlimit(10 ** 6)
# n, k = map(int, input().split())
# def josephus(num):
#     if k == 1:
#         return num-1
#     if num == 1:
#         return 0
#     elif num<k :
#         return (josephus(num-1)+k)%num
#     else:
#         Q, r = num//k, num%k
#         j = josephus(num-Q)
#         if j <= r+k-2:
#             return (j + Q*k) % num
#         else:
#             return (j + Q*k + (j-r)//(k-1)) % num
# print(josephus(n) + 1)
