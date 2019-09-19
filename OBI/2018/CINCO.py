i = int(input())
num = [int(i) for i in input().split()]
maior = -float('inf')
indice = 0

for i,x in enumerate(num[:-1]):
    if x % 5 == 0 and num[-1] - x >= maior:
        maior = num[-1] - x
        indice = i
        if maior > 0:
            break

if maior == -float('inf'):
    print(-1)
    
else:
    num[indice], num[-1] = num[-1], num[indice]

    num = [str(i) for i in num]
    print(' '.join(num))
