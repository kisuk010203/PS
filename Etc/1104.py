# # ls = list(map(int, input().split()))
# # ls2 = [1,1,2,2,2,8]
# # for idx in range(len(ls)):
# #     print(ls2[idx] - ls[idx], end = " ")

# # n, r = map(int, input().split())
# # ans = 1
# # r = min(r, n-r)
# # for i in range(r):
# #     ans *= (n-i)
# # for i in range(r):
# #     ans //= (i+1)
# # print(ans)

# # n, k = map(int, input().split())
# # wvlist = []
# # knapsack = [[0]*(k+1) for _ in range(n)]
# # for _ in range(n):
# #     wvlist.append(tuple(map(int, input().split())))
# # wvlist = sorted(wvlist, key = lambda x: x[1])
# # for idx in range(n):
# #     for cap in range(k+1):
# #         if cap >= wvlist[idx][0]:
# #             knapsack[idx][cap] = max(knapsack[idx-1][cap], knapsack[idx-1][cap-wvlist[idx][0]] + wvlist[idx][1])
# #         else:
# #             knapsack[idx][cap] = knapsack[idx-1][cap]
# # print(knapsack[n-1][k])


# # T = int(input())
# # for _ in range(T):
# #     N = int(input())
# #     coinlist = list(map(int, input().split()))
# #     money = int(input())
# #     knapsack = [[0]*coinlist[i] + [1] for i in range(N)]
# #     for kn in knapsack:
# #         kn[0] = 1
# #     for start in range(N-1, -1, -1):
# #         for item in range(coinlist[start]+1, money+1):
# #             s = 0
# #             for coinidx in range(start, N):
# #                 if coinlist[coinidx] <= item:
# #                     s += knapsack[coinidx][item - coinlist[coinidx]]
# #             knapsack[start].append(s)
# #     print(knapsack[0][money])

# #2447
# # N = int(input())
# # starlist = [["*"]*N for _ in range(N)]
# # def setstar(row, col, k):
# #     if k==1:
# #         return
# #     for r in range(k//3):
# #         for c in range(k//3):
# #             starlist[r + row + k//3][c + col + k//3] = " "
# #     for i in range(3):
# #         for j in range(3):
# #             if i*j != 1:
# #                 setstar(row + k//3 * i, col + k//3 * j, k//3)
# # setstar(0, 0, N)
# # for itm in starlist:
# #     for item in itm:
# #         print(item, end = "")
# #     print()

# import sys
# import random
# from collections import defaultdict

# sys.setrecursionlimit(10**5)
# prime = [2,3,5,7,11,13,17,23,29,31,37,41]
# factordict = defaultdict(int)
# def gcd(a, b):
#     while(b!=0):
#         a, b = b, a%b
#     return a
# def powermod(a, b, n):
#     ans = 1
#     while b>0:
#         if b%2 != 0:
#             ans = (ans*a)%n
#         b//=2
#         a = (a*a)%n
#     return ans

# def millerrabin(n, p):
#     if(n%p ==0):
#         return True
#     cnt, d = 0, n-1
#     while(d%2 == 0):
#         cnt+=1
#         d//=2
#     temp = powermod(p, d, n)
#     if temp == 1 or temp == n-1:
#         return True
#     for _ in range(cnt-1):
#         temp = powermod(temp, 2, n)
#         if temp == n-1:
#             return True
#     return False

# def isPrime(n):
#     for item in prime:
#         if n == item:
#             return True
#         if not millerrabin(n, item):
#             return False
#     return True
# def pollardrho(n):
#     if n==1:
#         return
#     if n%2 == 0:
#         factordict[2] += 1
#         pollardrho(n//2)
#         return
#     if isPrime(n):
#         factordict[n] += 1
#         return

#     x = random.randint(1,2)
#     y = x
#     c = (random.randint(1,11)) % (n-1)
#     factor = 1
#     while(factor == 1):
#         x = (powermod(x, 2, n) + c + n)%n
#         y = (powermod(y, 2, n) + c + n)%n
#         y = (powermod(y, 2, n) + c + n)%n
#         factor = gcd(abs(x-y), n)
#     if(factor == n):
#         return pollardrho(n)
#     pollardrho(factor)
#     pollardrho(n//factor)

# t = int(sys.stdin.readline())
# for _ in range(t):
#     n = int(sys.stdin.readline())
#     if(n%4 == 0):
#         print(-1)
#         continue
#     for i in factordict:
#         factordict[i] = 0
#     pollardrho(n)
#     explist = list(factordict.values())
#     print(explist)
#     if min(explist) > 1:
#         print(-1)
#     else:
#         ans = 1
#         for i in range(1, len(explist)+1):
#             ans *= i
#         print(ans)

# import sys
# momax = 400000
# k = int(sys.stdin.readline())
# mo = [0] *momax
# def setMobius():
#     mo[1] = 1
#     for i in range(1,momax):
#         for j in range(2*i, momax, i):
#             mo[j] -= mo[i]
# def findSquareFree(n):
#     cnt = 0
#     i=1
#     while(i**2<=n):
#         cnt += (n//(i**2))*mo[i]
#         i+=1
#     return cnt
# setMobius()
# left, right = 1, k*2
# while left<=right:
#     mid = (left+right)//2
#     num = findSquareFree(mid)
#     if num >= k:
#         right = mid-1
#     else:
#         left = mid+1
# print(left)


# import sys
# n = int(sys.stdin.readline())
# seq = list(map(int, sys.stdin.readline().split()))
# sortedSeq = sorted(seq)
# numdict = {}
# cnt = 0
# for item in sortedSeq:
#     if item not in numdict:
#         numdict[item] = cnt
#         cnt += 1
# for item in seq:
#     print(numdict[item], end = " ")



import sys
sys.setrecursionlimit(10**6)
n = int(sys.stdin.readline())
adjdict = []
cntodd = 0
for _ in range(n):
    i, d, s= 0, {}, 0
    for item in map(int, sys.stdin.readline().split()):
        if item != 0:
            d[i] = item
        i += 1
        s += item
    adjdict.append(d)
    if s%2 == 1:
        cntodd += 1
eulerlist = []
def dfs(start):
    while adjdict[start]:
        ls = [item for item in adjdict[start].keys()]
        for end in ls:
            try:
                adjdict[start][end] -= 1
                adjdict[end][start] -= 1
                if adjdict[start][end] == 0:
                    del adjdict[start][end]
                    del adjdict[end][start]
                dfs(end)
            except:
                continue
    eulerlist.append(start)
if cntodd != 0:
    print(-1)
else:
    dfs(0)
    for item in eulerlist[::-1]:
        print(item+1, end = " ")
