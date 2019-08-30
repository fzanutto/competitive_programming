def bfs():
    while fila: 
        atual, d = fila.pop(0)
       
        if atual[0]+1 < n and visitados[atual[0]+1][atual[1]] == -1:
            fila.append(((atual[0]+1, atual[1]), d+1))
            visitados[atual[0]+1][atual[1]] = d

        if 0 <= atual[0]-1 and visitados[atual[0]-1][atual[1]] == -1:
            fila.append(((atual[0]-1, atual[1]), d+1))
            visitados[atual[0]-1][atual[1]] = d
            
        if 0 <= atual[1]-1 < m and visitados[atual[0]][atual[1]-1] == -1:
            fila.append(((atual[0], atual[1]-1),d+1))
            visitados[atual[0]][atual[1]-1] = d

        if atual[1]+1 < m and visitados[atual[0]][atual[1]+1] == -1:
            fila.append(((atual[0], atual[1]+1), d+1))
            visitados[atual[0]][atual[1]+1] = d
casos = int(input())
for c in range(casos):
    if c != 0:
        input()
        
    n, m = [int(b) for b in input().split()]
    
    visitados = [[-1]*m for u in range(n)]
    fila = []

    for a in range(n):
        inp = input()
        for x in range(m):
            if inp[x] == '1':
                visitados[a][x] = 0
                fila.append(((a,x),1))
    bfs()
    
    for y in visitados:
        print(*y)
