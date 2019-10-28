for _ in range(int(input())):
    a,b,c,d,k = [int(i) for i in input().split()]
    
    x = (a+c-1)//c
    y = (b+d-1)//d
    
    if x+y <= k:
        print(x,y)
    else:
        print(-1)
    
    
