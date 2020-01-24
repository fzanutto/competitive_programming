n,m,k = [int(i) for i in input().split()]
p = []
for i in range(m):
    p.append(int(input()))

res = 0

F = int(input())


for x in p:
    dif = x^F
    temp = 0
    while dif:
        if dif & 1:
            temp += 1
        dif >>= 1
    if temp <= k:
        res += 1
print(res)
