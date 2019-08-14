def mochila(indices, espaco):

    memo = [ 0 for i in range(maximo+1) ]
    
    for i in range(espaco+1):
        for j in range(len(indices)):
            if pesos[j] <= i:
                memo[i] = max(memo[i], memo[i - pesos[j]] + valores[j])

    return memo[espaco]
