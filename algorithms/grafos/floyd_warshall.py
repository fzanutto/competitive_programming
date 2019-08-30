from itertools import product
def floyd_warshall(n, edge):

    rn = range(n)
    dist = [ [float('inf')] * n for i in rn]

    for i in rn:
        dist[i][i] = 0
        
    for src, dest, distance in edge:
        dist[src-1][dest-1] = distance
        
    for k, i, j in product(rn, repeat=3):
        new_dist = dist[i][j] + dist[j][k]
        if new_dist < dist[i][k]:
            dist[i][k] = new_dist

    return dist


grafo = [[1,2,1], [1,3,5], [1,4,6], [2,1,1], [2,3,1], [3,1,5], [3,2,1], [3,4,1], [4,1,6], [4,3,1]]
print(floyd_warshall(4, grafo))
