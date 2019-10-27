n = int(input())

matriz = []
for i in range(1,10):
    for j in range(1,10):
        matriz.append(i*j)

if n in matriz:
    print('Yes')
else:
    print('No')
