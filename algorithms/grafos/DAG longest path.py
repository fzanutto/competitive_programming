def toposort(grafo, nodo, stack, visitados):
    visitados[nodo] = True

    for i in grafo[nodo]:
        if visitados[i] == False:
            toposort(grafo, i, stack, visitados)

    stack.insert(0, nodo)


def longestPath(n, grafo, inicios):
    stack = []
    visitados = {i:False for i in grafo}
    dist = [-float('inf')] * (n+1)
    
    for i in grafo:
       if visitados[i] == False:
            toposort(grafo, i, stack, visitados)
    
    for i,v in enumerate(inicios):
        if v:
            dist[i] = 0

    while stack:
        u = stack.pop(0)
            
        for i in grafo[u]:
            dist[i] = max(dist[u] + grafo[u][i], dist[i])
    
    return max(dist)
    

n,m = [int(i) for i in input().split()]

grafo = {i:{} for i in range(1,n+1)}
inicios = [True for i in range(n+1)]
inicios[0] = False
for i in range(m):
    a,b,c = [int(x) for x in input().split()]
    grafo[a][b] = max(c, grafo[a].get(b, 0)) #para mais de um caminho entre 2 nodos
    inicios[b] = 0

print(longestPath(n, grafo, inicios))
