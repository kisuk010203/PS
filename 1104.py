# import sys
# n = int(sys.stdin.readline())
# seq = list(map(int, sys.stdin.readline().split()))
# m =  int(sys.stdin.readline())
# targ = list(map(int, sys.stdin.readline().split()))
# seq.sort()
# for i in range(m):
#     left, right = 0, n-1
#     while left<= right:
#         mid = (left+right)//2
#         if seq[mid]<targ[i]:
#             left = mid+1
#         elif seq[mid] > targ[i]:
#             right = mid-1
#         else:
#             left = mid
#             break
#     print(seq[left] == targ[i])


a = input()
print(a+"!")