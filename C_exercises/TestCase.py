# from collections import defaultdict
# def dothis(N):
#     d = defaultdict(int)
#     n = len(N)
#     ls = []
#     for item in N:
#         ls.append(int(item))
#     if n>=2:
#         for i in range(10):
#             d[i] += pow(10, n-2) * (n-1)
#         d[0] -= (pow(10, n-1) - 1)//9

#     for i in range(1, ls[0]):
#         d[i] += pow(10, n-1)
#         for j in range(10):
#             d[j] += (n-1) * pow(10, n-2)
#     if n == 1:
#         d[int(N)] += 1
#     for i in range(1, n):
#         if i == n-1:
#             for item in ls[:i]:
#                 d[item] += ls[i] + 1
#             for item in range(ls[i] + 1):
#                 d[item] += 1
#             continue
#         for item in ls[:i]:
#             d[item] += (ls[i]) * pow(10, n-i-1)
#         for j in range(ls[i]):
#             d[j] += pow(10, n-i-1)
#         if n-i-2>=0:
#             for k in range(10):
#                 d[k] += pow(10, n-i-2) * (n-i-1) * ls[i]
#     return int(sum(d[item]*item for item in range(10)))

# L, U = input().split()
# if int(L) <= 1:
#     print(dothis(U))
# else:
#     print(dothis(U) - dothis(str(int(L) - 1)))


# d = dict()
# chooseDict = dict()
# d[0], d[1], d[2] = 1, 1, 1
# div = 1000000
# num = int(input())
# chooseDict[(3,2)] = 3
# for i in range(1, num + 1):
#     chooseDict[(i, 0)] = 1
#     chooseDict[(i,1)] = i
#     chooseDict[(i,i)] = 1
# for i in range(3, num + 1):
#     for j in range(2, i//2 + 1):
#         chooseDict[(i, j)] = (chooseDict[(i-1, j)] + chooseDict[(i-1, j-1)])%div
#         chooseDict[(i,i-j)] = chooseDict[(i,j)]
# if num <= 2:
#     print(d[num] * num)
# else:
#     for idx in range(3, num + 1):
#         s = 0
#         for i in range(0, idx, 2):
#             s += (((d[i]*d[idx - i - 1])%div)*chooseDict[(idx-1, min(i, idx-i-1))])%div
#         d[idx] = s%div
#     print((2*d[num])%div)

# N, M = map(int, input().split())
# ls = []
# for _ in range(M):
#     ls.append(list(map(int, input().split())))
# minPack = min(list(item[0] for item in ls))
# minOne = min(list(item[1] for item in ls))
# if 6*minOne <= minPack:
#     print(N * minOne)
# else:
#     print(min(minOne * (N%6), minPack) + (N//6)*minPack)

# L, R = input().split()
# L = "0"*(len(R) - len(L)) + L
# cnt = 0
# for i in range(len(L)):
#     if L[i] != R[i] :
#         break
#     elif L[i] == "8":
#         cnt += 1
# print(cnt)

# def gcd(a, b):
#     if a == b or b == 0:
#         return a
#     return gcd(b, a%b)
# N, M = map(int, input().split())
# N = N%M
# if N == 0:
#     print(0)
# else:
#     print(M - gcd(M, N))

# x, y, w, h = map(int, input().split())
# print(min(x, y, w-x, h-y))


# N = int(input())

# ls = []
# for _ in range(N):
#     s = input()
#     if s[2] == ".":
#         ls.append(0)
#         continue
#     ls.append(int(s[2:])%1000)

# for i in range(1, 1001):
#     for item in ls:
#         error = -1*((item*i)%-1000)
#         if error >= i:
#             break
#     else:
#         print(i)
#         break

# LC, LH = map(int, input().split())
# numx = int(input())
# cutx = set(map(int, input().split()))
# numy = int(input())
# cuty = list(map(int, input().split()))
# if LH in cutx and -1*LH in cutx:
#     b, d = 0, 0
#     for i in cutx:
#         if (-1)*LH < i < LH:
#             b += 1
#     for j in cuty:
#         if j>LH or j<(-1)*LH:
#             d += 1
#     print((numx-b)*(numy+1) + (b+1)*(d+2))
# elif LH in cuty and -1*LH in cuty:
#     b, d = 0, 0
#     for i in cuty:
#         if (-1)*LH < i < LH:
#             b += 1
#     for j in cutx:
#         if j>LH or j<(-1)*LH:
#             d += 1
#     print((numy-b)*(numx+1) + (b+1)*(d+2))
# else:
#     b, d = 0, 0
#     for i in cuty:
#         if (-1)*LH <= i <= LH:
#             b += 1
#     for j in cutx:
#         if (-1)*LH <= j <= LH:
#             d += 1
#     if b**2 + d**2 == 0:
#         print((numx + 1)*(numy + 1))
#     else:
#         print((numx + 1)*(numy + 1) - (b-1)*(d-1))


# import math

# s, p = map(int, input().split())
# if s == p:
#     print(1)
# else:
#     x = s/math.e
#     for n in range(2, int(x+3)):
#         if n * math.log(s) >= math.log(p) + n*math.log(n):
#             print(n)
#             break
#     else:
#         print(-1)





# n, k = map(int, input().split())
# parDict = dict()
# def setParDict(curr, open, fault):
#     if curr == n :
#         k = int(fault or open!=0)
#         parDict[(curr, open, fault)] = k
#         return k
#     if (curr, open, fault) in parDict:
#         return parDict[(curr, open, fault)]
#     k = setParDict(curr + 1, open + 1, fault) + setParDict(curr + 1, open - 1, fault or open <= 0)
#     parDict[(curr, open, fault)] = k
#     return k

# def findK(curr, open, fault, k):
#     if curr == n:
#         return -1
#     if parDict[(curr+1, open+1, fault)] >= k:
#         if curr == n-1 and k == 2:
#             print(")", end = "")
#         else:
#             print("(", end = "")
#             findK(curr+1, open+1, fault, k)
#     else:
#         print(")", end = "")
#         findK(curr+1, open-1, fault or open<=0, k - parDict[(curr+1, open+1, fault)])

# setParDict(0,0,False)
# if k >= parDict[(0, 0, False)]:
#     print(-1)
# else:
#     findK(0, 0, False, k+1)

# s = input()
# password = input()
# alphDict = dict()
# i, div, n, ans, k = 1, 900528, len(s), 0, len(password)
# d = dict()
# d[0] = 1
# for item in s:
#     alphDict[item] = i
#     i += 1
# for i in range(1, k + 1):
#     d[i] = (d[i-1] * n)%div
# for i in range(k):
#     ans = (ans + (alphDict[password[i]]) * d[k-i-1])%div
# print(ans)





# n, k = map(int, input().split())
# parDict = dict()
# def setParDict(curr, open):
#     if open <0 :
#         parDict[(curr, open)] = 0
#         return 0
#     if curr == n :
#         k = int(open==0)
#         parDict[(curr, open)] = k
#         return k
#     if (curr, open) in parDict:
#         return parDict[(curr, open)]
#     k = setParDict(curr + 1, open + 1) + setParDict(curr + 1, open - 1)
#     parDict[(curr, open)] = k
#     return k

# def findK(curr, open, k):
#     if curr == n:
#         return -1
#     if parDict[(curr+1, open+1)] >= k:
#         print("(", end = "")
#         findK(curr+1, open+1, k)
#     else:
#         print(")", end = "")
#         findK(curr+1, open-1, k - parDict[(curr+1, open+1)])

# setParDict(0,0)
# if k >= parDict[(0, 0)]:
#     print(-1)
# else:
#     findK(0, 0, k+1)




# A, B = map(int, input().split())
# isPrime = [False]*2 + [True] * (B-1)
# primenumDict = dict()
# primenumDict[1] = 0
# for i in range(2, B+1):
#     for j in range(2*i, B+1, i):
#         isPrime[j] = False
#     if i*i > B+1:
#         break
# primeList = [item for item in range(2, B+1) if isPrime[item]]
# cnt = 0
# for i in range(2, B+1):
#     if i in primeList:
#         primenumDict[i] = 1
#         continue
#     else:
#         for j in primeList:
#             if i%j == 0:
#                 primenumDict[i] = primenumDict[i//j] + 1
#                 break
#     if i>= A and primenumDict[i] in primeList:
#         cnt += 1
# print(cnt)

# A, B = [], []
# def change(s):
#     if s == "0":
#         return "1"
#     return "0"
# def interchange(a, b):
#     for i in range(a, a+3):
#         for j in range(b, b+3):
#             A[i][j] = change(A[i][j])

# m, n = map(int, input().split())
# for _ in range(m):
#     A.append(list(input()))
# for _ in range(m):
#     B.append(list(input()))
# def cannum():
#     cnt = 0
#     if m<3 or n<3:
#         return int(A==B) - 1
#     for i in range(m-2):
#         for j in range(n-2):
#             if A[i][j] != B[i][j]:
#                 interchange(i, j)
#                 cnt += 1
#         if A == B:
#             return cnt
#     return -1
# print(cannum())



# colorCost = []
# dp = dict()
# N = int(input())
# for i in range(N):
#     colorCost.append([i, list(map(int, input().split()))])
# for last in range(3):
#     dp[(0, last)] = colorCost[0][1][last]
# for length in range(1,N):
#     for last in range(3):
#         dp[(length, last)] = min(dp[(length-1, (last+1)%3)], dp[(length-1, (last+2)%3)]) + colorCost[length][1][last]

# print(min([dp[(N-1,i)] for i in range(3)]))


# N = int(input())
# searched = [False] * N
# quantity = [1] + [0]*(N-1)
# ls = [[] for _ in range(N)]
# def gcd(a, b):
#     if b == 0:
#         return a
#     return gcd(b, a%b)
# def lcm(a, b):
#     return a*b//gcd(a,b)
# for _ in range(N-1):
#     a, b, p, q = map(int, input().split())
#     p, q = p//gcd(p, q), q//gcd(p, q)
#     ls[a].append([b, p, q])
#     ls[b].append([a, q, p])


# def allSearched():
#     for item in searched:
#         if not item:
#             return False
#     return True
# def dfs(start):
#     if allSearched():
#         return
#     searched[start] = True
#     for item in ls[start]:
#         if not searched[item[0]]:
#             k, q = lcm(quantity[start], item[1]), quantity[start]
#             for i in range(N):
#                 quantity[i] *= (k//q)
#             quantity[item[0]] = (k//item[1]) * item[2]
#             dfs(item[0])
# dfs(0)
# for item in quantity:
#     print(item, end = " ")






# import sys
# sys.setrecursionlimit(10**6)
# T = int(input())
# cntlist = []
# for _ in range(T):
#     col, row, numCab = map(int, input().split())
#     cnt = 0
#     posCab = []
#     for _ in range(numCab):
#         posCab.append(tuple(map(int, input().split())))
#     searchDict = { item : False for item in posCab }
#     def dfs(start):
#         if searchDict[start]:
#             return
#         searchDict[start] = True
#         r, c = start[0], start[1]
#         for pos in [(r-1, c), (r, c-1), (r+1, c), (r, c+1)]:
#             if pos in posCab and not searchDict[pos]:
#                 dfs(pos)
#         return
#     for item in posCab:
#         if not searchDict[item]:
#             cnt += 1
#             dfs(item)
#     cntlist.append(cnt)
# for item in cntlist:
#     print(item)










N = int(input())
cnt = 0
parent = list(map(int, input().split()))
isLeaf = [True] * N
delNode = int(input())
def cutTree(parentnode):
    parent[parentnode] = -2
    for item in range(N):
        if parent[item] == parentnode:
            cutTree(item)
    return
cutTree(delNode)
for i in range(N):
    if parent[i] == -2:
        isLeaf[i] = False
    elif parent[i] >= 0:
        isLeaf[parent[i]] = False
for i in isLeaf:
    if i:
        cnt += 1
print(cnt)
