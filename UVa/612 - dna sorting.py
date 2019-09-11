# limites de inputs sao pequenos e limite de tempo grande, da pra fazer n^2

# Alunos: Fernando Zanutto e Guilherme Santana
# ID user UVa: 1046965
# ID submission: 23881170

def inversions(array):
    arr = array.copy()
    cont = 0
    for i in range(len(arr)):
        for j in range(i,len(arr)):
            if arr[j] < arr[i]:
                cont+=1
    return cont

for i in range(int(input())):
    input()
    if i != 0:
        print()
    n,m = [int(x) for x in input().split()]
    lista = []
    for x in range(m):
        lista.append((list(input()), x))
    lista.sort(key = lambda x: (inversions(x[0]), x[1]))

    for x in lista:
        print(*x[0], sep='')
    
