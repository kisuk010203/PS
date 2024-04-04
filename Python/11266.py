import sys

input = sys.stdin.readline
v, e = map(int, input().split())
graph = [[] for _ in range(v)]
for _ in range(e):
    a, b = map(int, input().split())
    graph[a - 1].append(b - 1)
    graph[b - 1].append(a - 1)

curr_cnt = 0
dfs_rank = [0] * v
is_articulated = [False] * v


def find_min_reach(node: int, is_root: bool) -> int:
    global curr_cnt
    curr_cnt += 1
    dfs_rank[node] = curr_cnt
    ret = dfs_rank[node]
    child_cnt = 0

    for child in graph[node]:
        if dfs_rank[child] == 0:
            child_cnt += 1
            child_ret = find_min_reach(child, False)
            ret = min(ret, child_ret)
            if not is_root and child_ret >= dfs_rank[node]:
                is_articulated[node] = True
        else:
            ret = min(ret, dfs_rank[child])
    if is_root and child_cnt >= 2:
        is_articulated[node] = True
    return ret


for i in range(v):
    if dfs_rank[i] == 0:
        find_min_reach(i, True)

print(sum(map(int, is_articulated)))
for idx, item in enumerate(is_articulated):
    if item:
        print(idx + 1, end=" ")
