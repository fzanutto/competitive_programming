while True:
    g,p = map(int, input().split())

    if g==p==0:
        break

    colocacoes = []
    sistemas = []
    pontos = []
    
    for i in range(0,g):
        colocacoes.append(list(map(int, input().split())))
    
    for i in range(0,int(input())):
        a = input().split()
        
        sistemas.append(list(map(int, a[1:])))

    for i,s in enumerate(sistemas):
        pontos.append([0]*p)
        maximo_pontos = len(s)
        for corrida in colocacoes:
            for piloto,pos in enumerate(corrida):
                if pos <= maximo_pontos:
                    pontos[i][piloto] += s[pos-1]                    

    for s in pontos:
        maior = max(s)
        if s.count(maior)>1:
            print(" ".join([str(i+1) for i,v in enumerate(s) if v==maior]))
        else:
            print(s.index(maior)+1)

