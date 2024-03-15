import sys
from math import gcd

d, k = map(int, sys.stdin.readline().split())
ret = d
if k % 2 == 0 and k >= 4 and d % 4 == 2:
    ret *= 2
while gcd(d, k) > 1:
    temp = gcd(d, k)
    k = k // temp
    ret *= temp
print(ret)
