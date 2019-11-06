for _ in range(int(input())):
    a,b,n,S = [int(i) for i in input().split()]
    
    if a*n < S:
        S -= a*n
    else:
        S -= S//n*n
    
    if S > b:
        print('NO')
    else:
        print('YES')
