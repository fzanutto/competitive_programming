def update(i, v):
    while i <= n:
        fenwick[i] += v
        i += i & -i

def getSum(i):
    s  = 0
    while i > 0:
        s += fenwick[i]
        i = i & (i-1)
    return s

n,q = [int(i) for i in input().split()]

lista = [0]
lista.extend([int(i) for i in input().split()])

fenwick = [0] * (n+1)

for i,v in enumerate(lista[1:]):
    update(i+1,v)

for _ in range(q):
    a = [int(i) for i in input().split()]

    if a[0] == 0:
        soma = a[2] - lista[a[1]]
        lista[a[1]] = a[2]
        update(a[1], soma)
    else:
        print(getSum(a[1]))
