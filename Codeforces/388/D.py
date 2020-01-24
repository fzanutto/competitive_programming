from math import log 
n = int(input())

lista = list(bin(n)[2:])

    
print(lista)

total = 2

for i,v in enumerate(lista[::-1]):
    if v == '1':
        print('add', len(lista)-i - 1)
        total += len(lista) - i
        if i != 0:
            total -= 1

total += len(lista)
print(total)

matriz = [[0] * total for i in range(total)]

#print(matriz)

last = len(lista) - 1

for i,v in enumerate(lista[:0:-1]):
    if v == '1':
        qtd = len(lista) - 1
        if i != 0:
            qtd -= 1
            
        for j in range(qtd - 1):
            matriz[last-j][last-j-1] = 'Y'
            matriz[last-j-1][last-j] = 'Y'
        
        matriz[last-j][0] = 'Y'
        matriz[0][last-j] = 'Y'
        
        last = last-j

for i in range(len(lista)):
    matriz[]

        
for i in matriz:
    print(*i)
        
        
