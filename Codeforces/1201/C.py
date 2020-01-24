def check(m): # m is value I'm trying to sum to median

    dif = lista[n//2] + m
    soma = 0
    for x in lista[n//2:]:

        soma += max(0, dif-x)

    return soma <= k

n,k = [int(i) for i in input().split()]


lista = [int(i) for i in input().split()]
lista.sort()


l = 0
r = 1000000001


while l < r:
    mid = (l+r+1)//2
    
    if check(mid):
        l = mid
    else:
        r = mid - 1
        
print(l + lista[n//2])
