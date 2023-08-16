# def erdos(n, m, k):
#     if m*k >= n+k:
#         return [1] + [item + 1 for item in erdos(n-1, m-1, k)]
#     elif m*k >= n+m:
#         return [n] + erdos(n-1, m, k-1)
#     else:
#         ls = []
#         for i in range(k, 0, -1):
#             for j in range(i, n+1, k):
#                 ls.append(j)
#         return ls

# n, m, k = map(int, input().split())
# if n > m*k or n+1 < m+k:
#     print(-1)
# else:
#     for item in erdos(n, m, k):
#         print(item, end = " ")

# n, m, k = map(int, input().split())
# if n == 1 or m>n or k>n:
#     print(-1)
# else:
#     m-=1
#     k-=1
#     num, pow = 1, 2
#     while n-1 >= pow:
#         if m//pow == k//pow: break
#         else:
#             num+=1
#             m//=pow
#             k//=pow
#     print(num)

# N = int(input())
# ls = list(map(int, input().split()))
# S = int(input())
# for idx in range(N):
#     ma = N
#     while True:
#         if idx == ls.index(max(ls[idx:ma])): break
#         else:
#             mb = ls.index(max(ls[idx:ma]))
#             if mb - idx <= S:
#                 S -= (mb - idx)
#                 ls = ls[0:idx] + [ls[mb]] + ls[idx:mb] + ls[mb+1:]
#             else:
#                 ma -= 1
# for item in ls:
#     print(item, end = " ")

# from collections import defaultdict
# N = input()
# d = defaultdict(int)
# n = len(N)
# ls = []
# for item in N:
#     ls.append(int(item))
# if n>=2:
#     for i in range(10):
#         d[i] += pow(10, n-2) * (n-1)
#     d[0] -= (pow(10, n-1) - 1)//9
    
# for i in range(1, ls[0]):
#     d[i] += pow(10, n-1)
#     for j in range(10):
#         d[j] += (n-1) * pow(10, n-2)
# if n == 1:
#     d[int(N)] += 1
# for i in range(1, n):
#     if i == n-1:
#         for item in ls[:i]:
#             d[item] += ls[i] + 1
#         for item in range(ls[i] + 1):
#             d[item] += 1
#         continue
#     for item in ls[:i]:
#         d[item] += (ls[i]) * pow(10, n-i-1)
#     for j in range(ls[i]):
#         d[j] += pow(10, n-i-1)
#     if n-i-2>=0:
#         for k in range(10):
#             d[k] += pow(10, n-i-2) * (n-i-1) * ls[i]
# for i in range(10):
#     print(int(d[i]), end = " ")

# num = int(input())
# ls = []
# for _ in range(num):
#     a, b = map(int, input().split())
#     ls.append([a%10 , b%4 + 4 * ((4-b%4)//4)])

# for item in ls:
#     s = pow(item[0], item[1])%10
#     print(s + ((10 - s)//10)*10)


# d, sd = dict(), dict()
# m, a, c, x, n, g = map(int, input().split())
# d[0] = a%m
# sd[0], sd[1] = 1%m, (1+a)%m
# for i in range(1, 60):
#     d[i] = (d[i-1] ** 2) % m
# for i in range(2, 60):
#     sd[i] = ((1 + d[i-1]) * sd[i-1]) % m
# def modPow(N):
#     s, mul = "", 1
#     while N>0:
#         s += str(N%2)
#         N //= 2
#     for i in range(len(s)):
#         if s[i] == '1':
#             mul = (mul * d[i]) % m
#     return mul
# def summodPow(N): 
#     s, sum, ba = "", 0, 1
#     while N>0:
#         s = str(N%2) + s
#         N //= 2
#     for i in range(len(s)):
#         if s[i] == "1":
#             sum = (sum + sd[len(s) - i - 1]*ba)%m
#             ba = (ba*d[len(s) - i - 1])%m
#     return sum
# X = (x*modPow(n) + summodPow(n)*c)%m
# print(X%g)


# T = int(input())
# ls = []
# for _ in range(T):
#     ls.append(list(map(int, input().split())))
#     N = int(input())
#     ls[-1].append(N)
#     for _ in range(N):
#         ls[-1].append(list(map(int, input().split())))
# def distSquare(x1, y1, x2, y2):
#     return (x2-x1)**2 + (y2-y1)**2
# def isDifferent(x1, y1, x2, y2, cx, cy, r):
#     return (r**2 - distSquare(x1, y1, cx, cy))*(r**2 - distSquare(x2, y2, cx, cy)) < 0

# for i in range(T):
#     x1, y1, x2, y2 = ls[i][0:4]
#     cnt = 0
#     for j in range(ls[i][4]):
#         cx, cy, r = ls[i][5+j]
#         if isDifferent(x1, y1, x2, y2, cx, cy, r):
#             cnt += 1
#     print(cnt)

# from math import sqrt


# def distSquare(x, y):
#     return sqrt(x**2 + y**2)

# X, Y, D, T = map(float, input().split())
# t, d = 0.0, distSquare(X,Y)
# if T>=D:
#     print(d)
# else:
#     if D>d:
#         print(min(d, T + D-d, 2*T))
#     else:
#         while d>=D*2:
#             t += T
#             d -= D
#         t += min(2*T, T + d-D)
#         print(t)

# import math

# ls = [1, 1]
# prime = [2, 3, 5, 7, 11, 13, 17]
# for i in range(2, 19):
#     ls.append(ls[-1] * i)
# def combi(n, k):
#     return ls[n]/(ls[n-k] * ls[k])
# p = float(input())
# q = float(input())
# p, q = p/100.0, q/100.0
# sump, sumq = 0.0, 0.0
# for item in prime:
#     sump += math.pow(p, item)*math.pow(1-p, 18 - item) * combi(18, item)
#     sumq += math.pow(q, item)*math.pow(1-q, 18 - item) * combi(18, item)

# print(sump + sumq - sumq*sump)

# ls = []
# N = int(input())
# def minHex(n):
#     for item in range(1000):
#         s = (item + 1)*(2*item + 1)
#         if s> n:
#             break
#         ls.append(s)
#     if n in (11, 26):
#         return 6
#     if n in ls:
#         return 1
#     for i in ls:
#         if n-i in ls:
#             return 2
#     if n>146858:
#         return 3
    
#     if n <= 146858:
#         for i in ls:
#             for j in ls:
#                 if n-i-j in ls:
#                     return 3
#     if n>130:    
#         return 4

#     for i in ls:
#         for j in ls:
#                 for k in ls:
#                     if n-i-j-k in ls:
#                         return 4
#     return 5 
# print(minHex(N))

# n, r, c = map(int, input().split())
# def find(n, r, c):
#     if n == 1:
#         return c + 2*r
#     else:
#         div = pow(2, n-1)
#         return pow(4, n-1) *find(1, r//div, c//div) + find(n-1, r%div, c%div)
# print(find(n, r, c))