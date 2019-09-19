from math import sqrt
matriz = []
n = int(input())
for i in range(n):
    matriz.append([int(x) for x in input().split()])

a1 = int(sqrt((matriz[0][1] * matriz[0][2]) / matriz[1][2] ))

res= [a1]

for i in range(1, n):
    res.append(matriz[0][i] // a1)

print(*res)
