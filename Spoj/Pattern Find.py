for i in range(int(input())):
    if i > 0:
        print()
    s,p = input().split()
    
    cont = 0
    inicio = 0
    indices = []
    add = len(p)
    
    while True:
        inicio = s.find(p, inicio)
        if inicio == -1:
            break
        
        indices.append(inicio+1)
        inicio += add
        cont += 1
        
    if cont == 0:
        print('Not Found')
    else:
        print(cont)
        print(*indices)
        
        
