# 0,1 KNAPSACK 12865
# n, k = map(int, input().split())
# wvlist = []
# knapsack = [[0]*(k+1) for _ in range(n)]
# for _ in range(n):
#     wvlist.append(tuple(map(int, input().split())))
# wvlist = sorted(wvlist, key = lambda x: x[1])
# for idx in range(n):
#     for cap in range(k+1):
#         if cap >= wvlist[idx][0]:
#             knapsack[idx][cap] = max(knapsack[idx-1][cap], knapsack[idx-1][cap-wvlist[idx][0]] + wvlist[idx][1])
#         else:
#             knapsack[idx][cap] = knapsack[idx-1][cap]
# print(knapsack[n-1][k])

#COINS 3067
# T = int(input())
# for _ in range(T):
#     N = int(input())
#     coinlist = list(map(int, input().split()))
#     money = int(input())
#     knapsack = [[0]*coinlist[i] + [1] for i in range(N)]
#     for kn in knapsack:
#         kn[0] = 1
#     for start in range(N-1, -1, -1):
#         for item in range(coinlist[start]+1, money+1):
#             s = 0
#             for coinidx in range(start, N):
#                 if coinlist[coinidx] <= item:
#                     s += knapsack[coinidx][item - coinlist[coinidx]]
#             knapsack[start].append(s)
#     print(knapsack[0][money])
    
#FROBENIUS 9115
# T = int(input())
# for _ in range(T):
#     froblist= list(map(int, input().split()))
#     ls , frobnum, frobcnt, consec = [True], -1, 0, 0
#     for i in range(1,1000001):
#         for item in froblist:
#             if item <= i and ls[i-item]:
#                 ls.append(True)
#                 consec += 1
#                 break
#         else:
#             ls.append(False)
#             consec = 0
#             frobcnt += 1
#             frobnum = i
#     if consec < min(froblist):
#         frobnum = -1
#     print(frobcnt)
#     print(frobnum)

#14728
# k, n = map(int, input().split())
# wvlist = []
# knapsack = [[0]*(k+1) for _ in range(n)]
# for _ in range(n):
#     wvlist.append(tuple(map(int, input().split())))
# wvlist = sorted(wvlist, key = lambda x: x[0])
# for idx in range(n):
#     for cap in range(k+1):
#         if cap >= wvlist[idx][1]:
#             knapsack[idx][cap] = max(knapsack[idx-1][cap], knapsack[idx-1][cap-wvlist[idx][1]] + wvlist[idx][0])
#         else:
#             knapsack[idx][cap] = knapsack[idx-1][cap]
# print(knapsack[n-1][k])

#22839
# coinlist = list(i**2 for i in range(1, 18))
# while True:
#     money = int(input())
#     if money == 0 : break
#     knapsack = [[0]*coinlist[i] + [1] for i in range(17)]
#     for kn in knapsack:
#         kn[0] = 1
#     for start in range(16, -1, -1):
#         for item in range(coinlist[start]+1, money+1):
#             s = 0
#             for coinidx in range(start, 17):
#                 if coinlist[coinidx] <= item:
#                     s += knapsack[coinidx][item - coinlist[coinidx]]
#             knapsack[start].append(s)
#     print(knapsack[0][money])

#1535
# n = int(input())
# loss = list(map(int, input().split()))
# happy = list(map(int, input().split()))
# knapsack = [[0]*(k+1) for _ in range(n)]

# for idx in range(n):
#     for cap in range(k+1):
#         if cap >= wvlist[idx][0]:
#             knapsack[idx][cap] = max(knapsack[idx-1][cap], knapsack[idx-1][cap-wvlist[idx][0]] + wvlist[idx][1])
#         else:
#             knapsack[idx][cap] = knapsack[idx-1][cap]