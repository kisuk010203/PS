import sys
input = sys.stdin.readline
print = sys.stdout.write

t = int(input())
ans = []
for _ in range(t):
    n = int(input())
    a = list(map(int, input().split()))
    if n == 1:
        print("0\n")
        continue
        
    x_0 = [0 for _ in range(n)]
    for i in range(2, n, 2):
        x_0[i] = x_0[i-2] + a[i-1] - a[i]
    x_0[n-2] = x_0[0] + a[0] - a[-1]
    for i in range(n - 4, 0, -2):
        x_0[i] = x_0[i+2] + a[i+2] - a[i+1]

    v_00 = [0 for _ in range(n)]

    for i in range(2, n, 2):
        v_00[i] = v_00[i-2] + x_0[i-1] - x_0[i-2]
    v_00[n-2] = v_00[0] + x_0[n-2] - x_0[n-1]

    for i in range(n - 4, 0, -2):
        v_00[i] = v_00[i+2] + x_0[i] - x_0[i+1]
    
    find_min = min(v_00)
    if find_min >= 0:
        print(" ".join(map(str, v_00)) + "\n")
    else:
        v_00 = [i - find_min for i in v_00]
        print(" ".join(map(str, v_00)) + "\n")