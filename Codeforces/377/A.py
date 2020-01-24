def bfs(i, j):
    global k
    visitado[i][j] = 1
    queue = [(i,j)]
    k-=1
    matriz[i][j] = '1'
    while queue:
        i,j = queue.pop(0)
            
        for x in [[0,1],[1,0],[0,-1],[-1,0]]:
            if 0 <= i+x[0] < n and 0 <= j+x[1] < m and matriz[i+x[0]][j+x[1]] == '.' and not visitado[i+x[0]][j+x[1]] and k:
                k -= 1
                visitado[i+x[0]][j+x[1]] = 1
                matriz[i+x[0]][j+x[1]] = '1'
                queue.append((i+x[0],j+x[1]))

n,m,need = [int(i) for i in input().split()]
visitado = [[0]*m for _ in range(n)]


matriz = []
inicio = (0,0)
c = 0
for i in range(n):
    matriz.append(list(input()))
    c += matriz[i].count('.')
k = c-need

for i in range(n):
    for j in range(m):
        if matriz[i][j] == '.':
            inicio = (i,j)
            break
    else:
        continue
    break

bfs(inicio[0], inicio[1])

for i in matriz:
    for j in i:
        if j == '1':
            print('.',end='')
        elif j == '.':
            print('X',end='')
        else:
            print(j, end='')
    print()

