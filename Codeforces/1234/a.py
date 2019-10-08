from math import ceil
t = int(input())

for i in range(t):
    g =int(input())
    lista =[int(i) for i in input().split()]
    print(ceil(sum(lista)/g))
    
    
