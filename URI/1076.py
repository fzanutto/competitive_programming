for i in range(int(input())):
    start = int(input())
    nodos, arestas = [int(i) for i in input().split()]
    grafo = [[0]*nodos for _ in range(nodos)]

    for _ in range(arestas):
        a,b = [int(a) for a in input().split()]

        grafo[a][b] = 1
        grafo[b][a] = 1
    cont = 0
    for x in grafo:
        for y in x:
            if y == 1:
                cont += 1
    print(cont)
