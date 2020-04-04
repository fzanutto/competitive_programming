def solve(case):
    n = int(input())
    
    matriz = []
    
    trace = 0
    r = set()
    c = set()
    
    for i in range(n):
        matriz.append([int(i) for i in input().split()])
        trace += matriz[i][i]
        
    col = {i:{} for i in range(1,n+1)}
    row = {i:{} for i in range(1,n+1)}

    for i in range(n):
        for j in range(n):
            if col[matriz[i][j]].get(j):
                c.add(j)
            col[matriz[i][j]][j] = True
            
            if row[matriz[i][j]].get(i):
                r.add(i)
            row[matriz[i][j]][i] = True
    print("Case #{}: {} {} {}".format(case, trace, len(r), len(c)))
    

for _ in range(int(input())):
    solve(_+1)
        
