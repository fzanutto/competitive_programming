n = int(input())
l = [int(i) for i in input().split()]
soma = 0

for i in range(n):
    for j in range(i+1, n):
        soma += l[i] * l[j]

print(soma)
