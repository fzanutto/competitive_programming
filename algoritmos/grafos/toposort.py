def toposort(grafo, nodo, stack):
    visitados[nodo] = True

    for i in grafo[nodo]:
        if visitados[i] == False:
            toposort(grafo, i, stack)

    stack.insert(0, nodo)


grafo = {'dish1': {'dish5': (2000, 250), 'dish3': (1000, 50)}, 'dish5': {'dish6': (3000, 50)}, 'dish2': {'dish5': (3000, 550), 'dish3': (2000, 50)}, 'dish3': {'dish5': (1000, 100), 'dish4': (3000, 200)}, 'dish4': {'dish5': (2000, 450), 'dish6': (2000, 450)}, 'base1': {'dish5': (4000, 750), 'dish1': (2000, 200)}, 'base2': {'dish1': (3000, 300), 'dish3': (5000, 1000), 'dish2': (2000, 200), 'dish6': (2000, 500), 'dish4': (5000, 400)}, 'dish6': {}}
visitados = {i:False for i in grafo}
ordenacao = []
for i in grafo:
    if visitados[i] == False:
        toposort(grafo, i, ordenacao)

print(ordenacao)
