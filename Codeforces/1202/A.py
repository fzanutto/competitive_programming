for _ in range(int(input())):


    a = int(input(), 2)
    b = int(input(), 2)
    
    
    j = 0
    
    while((b>>j) & 1 == 0):
        j += 1
    
    i = j
        
    while((a>>i) & 1 == 0):
        i += 1
    
        
    print(i-j)
