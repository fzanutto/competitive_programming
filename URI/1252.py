def compare(x):

    if x<0:
        mod = -((-x)%m)
    else:
        mod = x%m
        
    if x%2==0:
        a=x
    else:
        a=-x
    return mod, -(x%2), a
    

while True:

    n, m = [int(i) for i in input().split()]
    
    if (n,m) == (0,0):
        print(n,m)
        break
    lista = []
    for i in range(n):
        lista.append(int(input()))

    print(n,m)
    print(*sorted(lista, key=compare), sep="\n")
