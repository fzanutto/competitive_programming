while True:
    try:
        n = int(input())
        cost = int(input())
        receita = []
        for _ in range(n):
            receita.append(int(input()) - cost)
        
        m = 0
        
        for i in range(n):
            temp = 0
            # start on index i, go until j
            for j in range(i,n):
                temp += receita[j]
                
                if temp > m:
                    m = temp
        print(m)
    except EOFError:
        break
