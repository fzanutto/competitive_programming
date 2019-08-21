def dijkstra(start_node, graph):
    
    unvisited = {node: None for node in graph}
    current = start_node
    current_distance = 0
    unvisited[current] = 0
    visited = {}

    while True:
        for neighbour, distance in graph[current].items():
            if neighbour in unvisited:
                new_distance = current_distance + distance

                if unvisited[neighbour] is None or new_distance < unvisited[neighbour]:
                    unvisited[neighbour] = new_distance
        visited[current] = current_distance

        del unvisited[current]

        candidates = [node for node in unvisited.items() if node[1]]
        if not candidates:
            break
        current, current_distance = sorted(candidates, key = lambda x: x[1])[0]

    return visited

grafo = {'a':{'b':1, 'c':5,'d':6}, 'b': {'a':1, 'c':1}, 'c': {'a':5, 'b':1, 'd':1}, 'd':{'a':6, 'c':1}, 'e':{}}
print(dijkstra('a',grafo))
