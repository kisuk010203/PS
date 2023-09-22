import sys
s = sys.stdin.readline().strip()
numls = [(int)(item) for item in s if item != '-']
print(numls)
num_num = len(numls)
pos = [0 for _ in range(num_num)]
neg = [0 for _ in range(num_num)]
ans_pos = [0 for _ in range(num_num)]
ans_neg = [0 for _ in range(num_num)]
num_rev = 0
num_cnt = num_num-1
for item in range(len(s)-1, -1, -1):
    if s[item] == '-':
        num_rev += 1
    elif num_cnt == num_num-1:
        num_rev = 0
        pos[num_num-1] = 1
        neg[num_num-1] = 0
        num_cnt -= 1
    else:
        if num_rev%2 == 0:
            pos[num_cnt] = pos[num_cnt+1]+1
            neg[num_cnt] = neg[num_cnt+1]
        else:
            pos[num_cnt] = neg[num_cnt+1]+1
            neg[num_cnt] = pos[num_cnt+1]
        num_cnt -= 1
        num_rev = 0






