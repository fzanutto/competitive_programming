def mochila_01(indices, espaco_restante): #quant de coisas / espaço da mochila
        
    if not indices or espaco_restante == 0:
        return 0
        
    i = indices[0]

    temp = memo[espaco_restante][len(indices)-1]
    if temp != -1:
            return temp

    if pesos[i] > espaco_restante:
        res = mochila(indices[1:], espaco_restante)
        memo[espaco_restante][len(indices)-1] = res
        return res

    else:
        contando = valores[i] + mochila(indices[1:], espaco_restante-pesos[i])
        ignorando = mochila(indices[1:], espaco_restante)
        
        res = max(ignorando, contando)
        memo[espaco_restante][len(indices)-1] = res
        
        return res

#mochila sem limite
def mochila(indices, espaco):

    memo = [ 0 for i in range(maximo+1) ]
    
    for i in range(espaco+1):
        for j in range(len(indices)):
            if pesos[j] <= i:
                memo[i] = max(memo[i], memo[i - pesos[j]] + valores[j])

    return memo[espaco]
