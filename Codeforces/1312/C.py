def solve(n):
    global total
    necessarios = set()
    cont = 0
    while n:

        temp = n // k
        
        if n % k == 1:
            necessarios.add(cont)
            total += 1
        elif n % k > 1:
            return False
            
        cont += 1
        n = temp
         

    return necessarios     

for _ in range(int(input())):
    total = 0
    n,k = [int(i) for i in input().split()]
    
    l = [int(i) for i in input().split()]
    ans = set()
    
    for i in l:
        a = solve(i)
        if a == False:
            print('NO')
            break
        ans = ans.union(a)
    else:
        
        if len(ans) != total:
            print('NO')
        else:
            print('YES')
