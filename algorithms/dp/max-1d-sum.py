for i in range(int(input())):
    soma = 0
    res = 0
    inicio = 0
    inicioI = 0
    fim = 0
    lista = [int(input()) for i in range(int(input())-1)]
    
    for ind, v in enumerate(lista):
        soma += v

        if soma < 0:
            soma = 0
            inicioI = ind+1 #vai começar a contar no proximo
        
        elif soma > res or (soma == res and fim-inicio < ind - inicioI):
            res = soma
            fim = ind #termina no indice atual
            inicio = inicioI
            
    if res > 0:    
        print("The nicest part of route {} is between stops {} and {}".format(i+1, inicio+1, fim+2))
    else:
        print("Route %d has no nice parts" %(i+1))
        
             
               
