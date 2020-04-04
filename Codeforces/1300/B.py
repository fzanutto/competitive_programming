for _ in range(int(input())):


    n = int(input())
    
    l = [int(i) for i in input().split()]
    
    l.sort(reverse=True)

    ind = 0

    P = []
    S = []
    
    for i in l:
        if (ind % 2) == 0:
            P.append(i)
        else:
            S.append(i)

        ind += 1
    
    
    if n % 2 == 0:
        a = abs(P[(n//2)-1] - S[n//2])
        b = abs(S[(n//2)-1] - P[n//2])
        print(min(a,b))
        
        
    else:
        print(abs(P[n//2] - S[n//2]))
