import sys
input = sys.stdin.readline

class CondExpNode:
    def __init__(self, lhs, rhs, true_exp, false_exp):
        self.lhs = lhs
        self.rhs = rhs
        self.true_exp = true_exp
        self.false_exp = false_exp

cond_expr_match = {}

def parse(expr: str, start: int, end: int) -> CondExpNode:
    if start > end:
        return None
    if start == end:
        return CondExpNode(expr[start], expr[start], None, None)
    assert start + 4 in cond_expr_match
    return CondExpNode(expr[start], expr[start + 3], 
                       parse(expr, start + 5, cond_expr_match[start + 4] - 1 ), 
                       parse(expr, cond_expr_match[start + 4] + 1, end))

def check(n, adj) -> bool:
    check_list = [-1 for _ in range(n + 2)]
    cnt = 0
    def dfs(adj, cur, check_list):
        for child, edge_type in adj[cur]:
            if check_list[child] != -1:
                if edge_type and check_list[child] != check_list[cur]:
                    return False
                if not edge_type and check_list[child] == check_list[cur]:
                    return False
            else:
                if edge_type:
                    check_list[child] = check_list[cur]
                else:
                    check_list[child] = 1 - check_list[cur]
                if not dfs(adj, child, check_list):
                    return False
        return True
    for i in range(n + 2):
        if check_list[i] == -1:
            check_list[i] = 0
            if not dfs(adj, i, check_list):
                return False
            cnt += 1
    return cnt

def main():
    n = int(input())
    ans = 0
    ls = []
    expr = input().strip()
    stack = []
    for i, c in enumerate(expr):
        if c == "?":
            stack.append(i)
        elif c == ":":
            assert stack
            cond_expr_match[stack.pop()] = i
    root = parse(expr, 0, len(expr) - 1)
    # print(cond_expr_match)
    def dfs(root: CondExpNode):
        # print(f"{root.lhs} == {root.rhs}")
        if root.true_exp:
            ls.append((root.lhs, root.rhs, True))
            dfs(root.true_exp)
            ls.pop()
            ls.append((root.lhs, root.rhs, False))
            dfs(root.false_exp)
            ls.pop()
        else: # leaf node
            if root.lhs == "1":
                return
            else:
                adj = [[] for _ in range(n + 2)] # n is 0, n + 1 is 1
                if root.lhs != "0":
                    leaf_idx = ord(root.lhs) - ord('a')
                    # assert leaf_idx < n
                    adj[leaf_idx].append((n, True))
                    adj[n].append((leaf_idx, True))
                adj[n].append((n + 1, False))
                adj[n + 1].append((n, False))
                # print(ls)
                for edge in ls:
                    lhs = ord(edge[0]) - ord('a') if edge[0].isalpha() else n + ord(edge[0]) - ord('0')
                    rhs = ord(edge[1]) - ord('a') if edge[1].isalpha() else n + ord(edge[1]) - ord('0')
                    adj[lhs].append((rhs, edge[2]))
                    adj[rhs].append((lhs, edge[2]))
                res = check(n, adj)
                nonlocal ans
                if res:
                    ans += 2 ** (res - 1)
    
    dfs(root)
    print(ans)
    
main()
