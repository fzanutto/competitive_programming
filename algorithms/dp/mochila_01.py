#top-down
def mochila_01(indice, espaco_restante): #quant de coisas / espaço da mochila
        
    if indice == 0 or espaco_restante == 0:
        return 0

    temp = memo[espaco_restante][indice]
    
    if temp != -1:
        return temp
    
    res = mochila(indice + 1, espaco_restante)

    if espaco_restante >= pesos[indice]:
        contando = valores[indice] + mochila(indice + 1, espaco_restante - pesos[indice])
        
        res = max(res, contando)
    
    memo[espaco_restante][indice] = res
        
    return res

#bottom-up
def mochila(pesos, valores, custo_maximo):

    memo = [[0] * (custo_max+1) for _ in range(len(pesos)+1)]

    for i in range(1, len(pesos)+1):
        for j in range(custo_maximo+1):
            peso = pesos[i-1]
            if peso <= j:
                memo[i][j] = max(valores[i-1] + memo[i-1][j-peso], memo[i-1][j])
            else:
                memo[i][j] = memo[i-1][j]

    res = memo[len(pesos)][custo_maximo]
    
    w = custo_maximo
    espaco_usado = 0
    
    for i in range(len(pesos), 0, -1): 
        if res <= 0: 
            break
        if res == memo[i - 1][w]: 
            continue
        else: 
            espaco_usado += pesos[i-1]
            res = res - valores[i - 1]
            w = w - pesos[i - 1] 

    return memo[len(pesos)][custo_maximo], espaco_usado
