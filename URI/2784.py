def dijkstra(start, distances):
    
    unvisited = {node: None for node in distances} #using None as +inf

    visited = {}
    current = start
    currentDistance = 0
    unvisited[current] = currentDistance
    
    while True:
        for neighbour, distance in distances[current].items():
            if neighbour not in unvisited: 
                continue
            newDistance = currentDistance + distance
            if unvisited[neighbour] is None or unvisited[neighbour] > newDistance:
                unvisited[neighbour] = newDistance
        visited[current] = currentDistance
        del unvisited[current]
        
        if not unvisited: 
            break
        
        candidates = [node for node in unvisited.items() if node[1]]
        current, currentDistance = sorted(candidates, key = lambda x: x[1])[0]

    return visited


x,y = map(int, input().split())
grafo = {}

for i in range(y):

    a,b,c = input().split()
    
    if a not in grafo:
        grafo[a] = {}
    if b not in grafo:
        grafo[b] = {}

    grafo[a][b] = int(c)
    grafo[b][a] = int(c)

servidor = input()

res = dijkstra(servidor, grafo)
res.pop(servidor)
lista = res.values()

print(max(lista) - min(lista))

