n, k, p, w = map(int, input().split())
if p % w == 0:
    print(p // w)
else:
    print(p // w + 1)
