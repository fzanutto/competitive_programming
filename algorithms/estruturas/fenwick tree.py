lista = [1,5,2,6,5,8,4,3,6,8,8,3,2]
n = len(lista)
fenwick = [0] * (n+1)

def update(i, v):
    while i <= n:
        fenwick[i] += v
        i += i & -i

def getSum(i):
    sum  = 0
    while i > 0:
        sum += fenwick[i]
        i = i & (i-1)

    return sum


for i,v in enumerate(lista):
    update(i+1,v)

print(getSum(n))
update(1, 4)
print(getSum(n))


        
