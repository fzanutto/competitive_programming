while True:
    try:
        n = int(input())
        pontos = {}
        for _ in range(n):
            x,y = [int(i) for i in input().split()]
            if not pontos.get(y):
                pontos[y] = []
            pontos[y].append(x)
        
        for i in pontos:
            pontos[i].sort()
            
        maximo = 1
        for i in pontos:
        
            for v in range(2):

                if pontos.get(i+2):
                    temp = 1
                    i1 = 0
                    i2 = 0
                    #print(v)
                    while i1 < len(pontos[i]) and i2 < len(pontos[i+2]):
                        #print('pontos:', pontos[i][i1],pontos[i+2][i2], v)
                        #print('is:',i1,i2)
                        if pontos[i][i1] != pontos[i+2][i2] and (pontos[i][i1] < pontos[i+2][i2]) == v:
                            temp += 1
                            v = not v
                            #print(pontos[i][i1], pontos[i+2][i2], v)
                        if v:
                            i2 += 1
                        else:
                            i1 += 1
                        #print('is:',i1,i2, v)
                        #print('len:', len(pontos[i]), len(pontos[i+2]))
                        #print('temp:', temp)
                        
                    maximo = max(maximo, temp)
                
        print(maximo)
    except EOFError:
        break
