n,m,k,q = [int(i) for i in input().split()]

#matriz = [['']*m for _ in range(n)]

treasure = []

for _ in range(k):
    treasure.append([int(i) for i in input().split()])
    
treasure.sort()

safe = [int(i) for i in input().split()]

print(treasure)



    
