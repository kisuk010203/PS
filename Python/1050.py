import sys

input = sys.stdin.readline
explicit_strip = lambda x: x.strip()
n, m = map(int, input().strip().split())
string_to_idx = {}
idx_to_string = []
idx_to_price = []

def get_or_create_idx(ingr, price=None):
    if ingr not in string_to_idx:
        string_to_idx[ingr] = len(string_to_idx)
        idx_to_string.append(ingr)
        idx_to_price.append(price or -1)
    return string_to_idx[ingr]

for i in range(n):
    ingr, price = map(explicit_strip, input().strip().split())
    get_or_create_idx(ingr, int(price))

recipe_list = []
for i in range(m):
    expr = input().strip()
    potion, form = map(explicit_strip, expr.split("="))
    ingr_list = form.split("+")

    recipe_list.append([get_or_create_idx(potion)] + [(int(item[0]), get_or_create_idx(item[1:])) for item in ingr_list])

flag = True
while flag:
    flag = False
    for recipe in recipe_list:
        potion, *ingr_list = recipe
        price = 0
        for num, ingr_idx in ingr_list:
            if idx_to_price[ingr_idx] == -1:
                break
            price += num * idx_to_price[ingr_idx]
        else:
            if idx_to_price[potion] == -1 or idx_to_price[potion] > price:
                idx_to_price[potion] = price
                flag = True

if "LOVE" in string_to_idx:
    print(min(idx_to_price[string_to_idx["LOVE"]], 1000000001))
else:
    print(-1)