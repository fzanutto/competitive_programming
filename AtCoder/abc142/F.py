def bfs(i):
    queue = [(i,1)]
    
    while queue:
        u,d = queue.pop(0)
            
        for v in grafo[u]:
            next[u] = v
            if v == i:
                return u,d
            
            queue.append((v,d+1))
        
def dfs(i, cont):
    if i == inicio:
        return cont
        
    visited[i] = True
    
    for v in grafo[i]:
        if visited[v]:
            continue
            
        if dfs(v):
            next[i] = v
            
            
n,m = [int(i) for i in input().split()]

grafo = {i:[] for i in range(1, m+1)}
next = [0] * (n+1)


for _ in range(m):
    a,b = [int(i) for i in input().split()]
    grafo[a].append(b)

i=0
res = False

# achar qualquer ciclo
while not res and i < n:
    i+=1
    res = bfs(i)

if not res:
    print(-1)
    
else:
    
    final = i

    v = res[0]
    d = res[1]

    candidatos = []
    while next[i] != final:
        candidatos.append(i)
        i = next[i]

    candidatos.append(v)

    res = float('inf')
    caminho = None

    for i in candidatos:
        inicio = i
        temp = dfs(i)
        
        if temp[1] < res:
            res = temp[1]
            caminho = [i, next]
    print(res)
    i = caminho[0]
    while next[i] != caminho[0]:
        print(i)
        i = next[i]
    print(i)
