from itertools import product

def empresa_para_int(empresa):
    res = 0
    for i in empresa:
        res |= 1 << ord(i)-ord('a')
    return res

def int_para_empresa(inteiro):
    if not inteiro:
        return '-'
    res = ''
    for i in range(0,26):
        a = ((inteiro >> i) & 1) * (i + ord('a'))
        if a:
            res += chr(a)
    return res

def floyd_warshall(n, edge, buscas):
    global empresa
    rn = range(n)
    nxt  = [[0] * n for i in rn]
    empresa = [ [0] * n for i in rn]
        
    for src, dest, empr in edge:
        empresa[src-1][dest-1] = empresa_para_int(empr)
        
    for k, i, j in product(rn, repeat=3):
        empresa[i][j] = (empresa[i][k] & empresa[k][j]) | empresa[i][j]
            
    res = {}
    for i, j in buscas:
        
        i=i-1
        j=j-1
        
        if not res.get(i+1):
            res[i+1]={}
        
        res[i+1][j+1] = empresa[i][j]

    return res

while True:
    
    v = int(input())
    if v == 0:
        break
    grafo = []
    buscas = []
    while True:
        x = input()
        if x == '0 0':
            break
        
        a,b,c = x.split()
        a=int(a)
        b=int(b)
        grafo.append([a,b,c])
    
    while True:
        x = input()
        
        if x == '0 0':
            break
        
        inicio,fim = map(int, x.split())
        buscas.append([inicio,fim])

    res = floyd_warshall(v, grafo, buscas)
    
    for i,j in buscas:
        empresas = res[i][j]
        if empresas:
            empresas = int_para_empresa(empresas)
            print(empresas)
        else:
            print('-')
    print()
