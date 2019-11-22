while True:
    n = int(input())
    if n == 0:
        break
       
       
    nomes = {}
    
    for i in range(n):
        a,b = input().split()
        nomes[a] = b
    ans = 0
    for i in range(int(input())):
        a,b = input().split()
        cont = 0
        for i in range(len(b)):
            if b[i] != nomes[a][i]:
                cont += 1
                if cont > 1:
                    ans+=1
                    break
    print(ans)
