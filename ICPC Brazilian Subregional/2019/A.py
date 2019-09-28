def bfs(i, j):

    fila = [i, j]
    
    while fila:
        i = fila.pop(0)
    
        for v in grafo[i]:
            if not visitados[v]:
                visitados[v] = True
                fila.append(v)
        

m,n,k = [int(i) for i in input().split()]

sensores = []
grafo = {
    0: [], # parede esquerda
    1: [], # parede cima
    2: [], # parede direita
    3: [], # parede baixo
}

indice = 4

for _ in range(k):
    x,y,r = [int(a) for a in input().split()]
    grafo[indice] = []
    
    # tratar casos de encostar nas paredes
    if x+r >= m:
        #parede da direita
        grafo[2].append(indice)
        grafo[indice].append(2)
    if x-r <= 0:
        grafo[0].append(indice)
        grafo[indice].append(0)
    if y+r >= n:
        grafo[1].append(indice)
        grafo[indice].append(1)
    if y-r <= 0:
        grafo[3].append(indice)
        grafo[indice].append(3)
    
    
    # tratar casos de outros sensores
    for i,s in enumerate(sensores):
        if (s[0]-x)**2 + (s[1]-y)**2 <= (s[2]+r)**2:
            # eles se encostam
            grafo[indice].append(i+4)
            grafo[i+4].append(indice)
            
    sensores.append([x,y,r])
    
    indice += 1

nao_pode = [
    [2,3],
    [0,1]
]
for i in range(2):
    visitados = [False]*(k+6)
    bfs(i*2,2*i+1)

    if visitados[nao_pode[i][0]] or visitados[nao_pode[i][1]]:
        print('N')
        break
else:
    print('S')
#caso haja caminho no grafo entre a entrada e a saida, significa que o caminho está bloqueado pelos sensores
