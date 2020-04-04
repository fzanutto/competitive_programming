for _ in range(int(input())):


    n = int(input())
    
    l = [int(i) for i in input().split()]
    
    a = sum(l)
    SUM = PROD = False
    
    if a != 0:
        SUM = True
    
    PROD = (0 not in l)
    
    if SUM and PROD:
        print(0)
    
    elif SUM and not PROD:
        ans = l.count(0)
        if ans + a == 0:
            ans += 1
        
        print(ans)
    
    elif PROD and not SUM:
        print(1)
    
    else:
        ans = l.count(0)
        if ans + a == 0:
            ans += 1
        print(ans)
    
