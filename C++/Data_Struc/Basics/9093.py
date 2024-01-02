import sys

t = int(sys.stdin.readline())
for i in range(t):
    ls = map(lambda x: x[::-1], sys.stdin.readline().split())
    for item in ls:
        print(item, end=" ")
    print()
