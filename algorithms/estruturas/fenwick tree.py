lista = [1,5,2,6,5,8,4,3,6,8,8,3,2]
n = len(lista)

fenwick = [0] * (n+1)

def update(i, v):
    while i <= n:
        fenwick[i] += v
        i += i & -i

# range update trick
# update range [l,r] with +q
# update(l, +q)
# update(r+1, -q)

def getSum(i):
    sum  = 0
    while i > 0:
        sum += fenwick[i]
        i = i & (i-1)

    return sum

def getSingle(i):
    val = fenwick[i]
    if i > 0:
        pai = i & (i-1)
        i -= 1
        while pai != i:
            val -= fenwick[i]
            i = i & (i-1)
            
    return val

for i,v in enumerate(lista):
    update(i+1,v)

print(getSum(n))
update(1, 4)
print(getSum(n))
