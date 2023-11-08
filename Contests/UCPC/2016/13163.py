import sys
n = int(sys.stdin.readline())
for i in range(n):
    name_list = sys.stdin.readline().split()
    print("god", end="")
    for j in range(1, len(name_list)):
        print(name_list[j], end="")
    print()
