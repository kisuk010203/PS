# ls = [1,2,3,4,5]
# print(ls[6:])
# print(ls[0:0])
# for i in range(5):
#     i +=1
#     print(i)

# a, b, c = [1, 2, 3]
# print(a)

# for i in range(10, -1, -1):
#     print(i, end =" ")

a = input()
quer = input()
flag = True
while flag:
    cnt1 = len(a)
    a = a.replace(quer, '')
    flag = cnt1 != len(a)
if len(a) == 0:
    print("FRULA")
else:
    print(a)
