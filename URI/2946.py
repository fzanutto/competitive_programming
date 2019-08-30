a = int(input(), 2)

res = []
for i in range(int(input())):
    temp = int(input())
    
    if a % temp == 0:
        res.append(temp)


if res:
    res.sort()
    print(*res)
else:
    print('Nenhum')
