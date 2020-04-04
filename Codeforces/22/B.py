n,m = [int(i) for i in input().split()]

matriz = []

for i in range(n):
    matriz.append(input())
    

ans = 4

for i in range(n):
    for j in range(m):  
        for k in range(i,n):
            for l in range(j,m):
                #print(i,j,k,l)
                block = False
                for x in range(i,k+1):
                    for y in range(j,l+1):
                        if matriz[x][y] == '1':
                            block = True
                if not block:
                    ans = max(ans, (k+1-i)*2 + (l+1-j)*2)
print(ans)
