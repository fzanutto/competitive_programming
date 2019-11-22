while True:
    a,d = [int(i) for i in input().split()]
    
    if a == 0 and d ==0:
        break
    
    atk = [int(i) for i in input().split()]
    defn = [int(i) for i in input().split()]
    
    atk.sort(reverse=True)
    defn.sort(reverse=True)

    ans = ""    

    if atk[-1] < defn[max(-2, -d)]:
        ans = "Y"
    else:
        ans = "N"
    
    print(ans)
            
    
    
