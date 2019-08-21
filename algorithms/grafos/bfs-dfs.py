def bfs(grafo, inicio): 

    visitados = {i:False for i in grafo}

    fila = [inicio] 

    visitados[inicio] = True

    while fila: 
        inicio = queue.pop(0)
        
        if not grafo[inicio]:
            continue
        
        for i in grafo[inicio]: 
            if visitados[i] == False: 
                fila.append(i) 
                visitados[i] = True


v = {i:False for i in grafo}
def dfs(grafo, inicio):
    for i in grafo[inicio]:
        if not v[i]:
            v[i] = True
            dfs(grafo, i)
