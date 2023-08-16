# 11725
# import sys
# n = int(sys.stdin.readline())
# nodelist = [[] for _ in range(n)]
# for _ in range(n-1):
#     a, b = map(int, sys.stdin.readline().split())
#     nodelist[a-1].append(b-1)
#     nodelist[b-1].append(a-1)
# parentlist = [-1]*n
# searchlist = [False]*n
# queue = list()
# def bfs(start):
#     queue.append(start)
#     while queue:
#         temp = queue.pop(0)
#         searchlist[temp] = True
#         for item in nodelist[temp]:
#             if not searchlist[item]:
#                 parentlist[item] = temp
#                 queue.append(item)
#     return
# bfs(0)
# for i in range(1, n):
#     print(parentlist[i]+1)
        
# import sys
# sys.setrecursionlimit(10**6)
# n = int(sys.stdin.readline())
# nodelist = [[] for _ in range(n)]
# dplist = [(-1,-1)]*n
# for _ in range(n-1):
#     a, b, c = map(int, sys.stdin.readline().split())
#     nodelist[a-1].append((b-1)*100+c)
# def dp(start):
#     if dplist[start] != (-1, -1):
#         return dplist[start]
#     if len(nodelist[start]) == 0:
#         dplist[start] = (0 , 0)
#         return dplist[start]
#     if len(nodelist[start]) == 1:
#         x = dp(nodelist[start][0] // 100)[0] + nodelist[start][0] %100
#         dplist[start] = (x, x)
#         return dplist[start]
#     x = dp(nodelist[start][0] // 100)[0] + nodelist[start][0] %100
#     y = dp(nodelist[start][1] // 100)[0] + nodelist[start][1] %100
#     x, y = max(x, y), min(x, y)
#     for i in range(2, len(nodelist[start])):
#         z = dp(nodelist[start][i] // 100)[0] + nodelist[start][i]%100
#         if z>x:
#             x, y = z, x
#         elif z>y:
#             y=z
#     dplist[start] = (x, x+y)
#     return dplist[start]
# dp(0)
# m = 0
# for item in dplist:
#     if item[1] > m:
#         m = item[1]
# print(m)
    
    
# import sys
# n, m, start = map(int, sys.stdin.readline().split())
# nodelist = [[] for _ in range(n)]

# for _ in range(m):
#     a, b = map(int, sys.stdin.readline().split())
#     nodelist[a-1].append(b-1)
#     nodelist[b-1].append(a-1)
# for item in nodelist:
#     item.sort()
# searchlist = [False]*n
# dfssearch = [False] * n
# queue = list()
# def dfs(start):
#     dfssearch[start] = True
#     print(start + 1, end = " ")
#     for item in nodelist[start]:
#         if not dfssearch[item]:
#             dfs(item)
# def bfs(start):
#     queue.append(start)
#     while queue:
#         temp = queue.pop(0)
#         if not searchlist[temp]:
#             print(temp +1, end = " ")
#         searchlist[temp] = True
#         for item in nodelist[temp]:
#             if not searchlist[item]:
#                 queue.append(item)
#     return
# dfs(start-1)
# print()
# bfs(start-1)

# import sys
# n = int(sys.stdin.readline())
# start, end = map(int, sys.stdin.readline().split())
# edge = int(sys.stdin.readline())
# nodelist = [[] for _ in range(n)]
# for _ in range(edge):
#     a, b = map(int, sys.stdin.readline().split())
#     nodelist[a-1].append(b-1)
#     nodelist[b-1].append(a-1)
# cntlist = [-1]*n
# cntlist[start-1] = 0
# def dfs(startnode):
#     for item in nodelist[startnode]:
#         if cntlist[item] == -1:
#             cntlist[item] = cntlist[startnode] + 1
#             dfs(item)
# dfs(start-1)
# print(cntlist[end-1])

# import sys
# def leftisland(worldmap):
#     for i in range(len(worldmap)):
#         for j in range(len(worldmap[i])):
#             if worldmap[i][j] == 1:
#                 return (i,j)
#     return False
# def dfs(worldmap, startx, starty):
#     worldmap[startx][starty] = -1
#     for idxx in range(startx-1, startx+2):
#         for idxy in range(starty-1, starty+2):
#             if idxx not in range(len(worldmap)) or idxy not in range(len(worldmap[0])):
#                 continue
#             if worldmap[idxx][idxy] == 1:
#                 dfs(worldmap, idxx, idxy)
    
# while True:
#     a, b = map(int, sys.stdin.readline().split())
#     if a == 0 and b == 0:
#         break
#     worldmap = []
#     for _ in range(b):
#         worldmap.append(list(map(int, sys.stdin.readline().split())))
#     cnt = 0
#     while leftisland(worldmap):
#         startx, starty = leftisland(worldmap)
#         dfs(worldmap, startx, starty)
#         cnt += 1
#     print(cnt)
        
# import sys
# vert, edge = map(int, sys.stdin.readline().split())
# nodelist = [[] for _ in range(vert)]
# searchlist = [False]*vert
# for _ in range(edge):
#     a, b = map(int, sys.stdin.readline().split())
#     nodelist[a-1].append(b-1)
#     nodelist[b-1].append(a-1)
# def leftunsearched():
#     for i in range(vert):
#         if not searchlist[i]:
#             return i+1
#     return False
# def dfs(start):
#     searchlist[start] = True
#     for item in nodelist[start]:
#         if not searchlist[item]:
#             dfs(item)
    
# cnt = 0
# while leftunsearched():
#     start = leftunsearched()-1
#     dfs(start)
#     cnt += 1
# print(cnt)

# import sys
# sys.setrecursionlimit(3000000)

# def dfs(y, x):
#     nodelist[y][x] = 2
#     for dy, dx in d:
#         Y, X = y+dy, x+dx
#         if Y in range(m) and X in range(n) and nodelist[Y][X] == 0:
#             dfs(Y, X)
            
# m, n= map(int, input().split())
# nodelist = [list(map(int, list(input()))) for _ in range(m)]
# d = [(-1, 0), (1, 0), (0, -1), (0, 1)]
# for j in range(n):
#     if nodelist[0][j] == 0:
#         dfs(m-1, j)
# print("YES" if 2 in nodelist[0] else "NO")

#1167
# from collections import deque
# import sys
# def bfs(x):
#     q = deque()
#     q.append(x)
#     c = [-1 for _ in range(n)]
#     c[x] = 0
#     while q:
#         x = q.popleft()
#         for item in nodelist[x]:
#             idx, w = item
#             if c[idx] == -1:
#                 c[idx] = c[x] + w
#                 q.append(idx)
#     return c.index(max(c)), max(c)

# n = int(sys.stdin.readline())
# nodelist = dict()

# for i in range(n):
#     edge = list(map(int, sys.stdin.readline().split()))
#     nodelist[edge[0]-1] = []
#     for j in range(1, len(edge)-1, 2):
#         nodelist[edge[0]-1].append((edge[j]-1, edge[j+1]))
# item = bfs(0)
# print(bfs(item[0])[1])

#1103
import sys
sys.setrecursionlimit(10**6)
n = int(sys.stdin.readline())
adjdict = {i:[] for i in range(n)}
for i in range(n):
    s = list(map(int, sys.readline().split()))
    for idx in range(n):
        if s[idx] != 0:
            adjdict[i].append((idx, s[idx]))
deglist = [sum(item[1]) for item in adjdict[j] for j in range(n)]
eulerlist = []
cntodd = 0
for deg in deglist:
    if deg%2 == 1:
        cntodd += 1

def dfs(start):
    end = 0
    while deglist[start] != 0:
        if adjmat[start][end] > 0:
            adjmat[start][end] -= 1
            adjmat[end][start] -= 1
            deglist[start] -= 1
            deglist[end] -= 1
            dfs(end)
        elif end < n-1:
            end += 1
    eulerlist.append(start)
if cntodd != 0:
    print(-1)
else:
    dfs(0)
    for item in eulerlist[::-1]:
        print(item+1, end = " ")
