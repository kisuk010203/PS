import sys
from collections import defaultdict
input = sys.stdin.readline

n = int(input())
a = list(map(int, input().split()))
q = int(input())
queries = [list(map(lambda x : int(x) - 1, input().split())) for _ in range(q)]
for query in queries:
    cnt = defaultdict(int)
    l, r = query
    for i in range(l, r + 1):
        cnt[a[i]] += 1
    max_ans = 0
    for val in cnt.values():
        max_ans = max(max_ans, val)
    print(max_ans)