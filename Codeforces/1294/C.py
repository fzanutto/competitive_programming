from math import sqrt

def fatores(n):
    fat = {}
    for p in range(2, int(sqrt(n)+1)):
        while n % p == 0:
            n/=p
            if not fat.get(p):
                fat[p] = 0
            fat[p]+=1
        p+=1

    if n > 1:
        fat[int(n)] = 1
    return fat
    
for _ in range(int(input())):
    n = int(input())
    f = [list(i) for i in fatores(n).items()]
    
    q = 0
    ans = [1,1,1]
    
    for i in range(len(f)):
        p,m = f[i]
        cont = 1
        
        while cont <= f[i][1]:
            f[i][1] -= cont
            ans[q] *= (f[i][0]**cont)
            
            cont += 1
            q+=1
            
            if q == 3:
                break
            
        if q == 3:
            break
            
#    print(q)
#    print(f)
    
    for i in f:
        ans[2] *= i[0]**i[1]
    if ans[0] != ans[1] and ans[0] != ans[2] and ans[1] != ans[2] and min(ans) >= 2:    
        print('YES')
        print(*ans)
    else:
        print('NO')

