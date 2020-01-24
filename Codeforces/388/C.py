n = int(input())

lista = []
aux = []

somaA = 0
somaB = 0

for i in range(n):
    a = [int(i) for i in input().split()][1:]
    if len(a) > 1:
        somaA += sum(a[0:len(a)//2])
        somaB += sum(a[-(len(a)//2):])

    if len(a) % 2 == 1:
        aux.append(a[len(a)//2])


aux.sort(reverse=True)

for i in range(0, len(aux), 2):
    somaA += aux[i]
for i in range(1, len(aux), 2):
    somaB += aux[i]
    
print(somaA, somaB)
