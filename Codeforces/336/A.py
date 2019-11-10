x,y = [int(i) for i in input().split()]

if x*y > 0:
    c = y+x
    
    c1 = (0,c)
    c2 = (c,0)
    if(c2 < c1):
        c1,c2=c2,c1
    print(c1[0],c1[1],c2[0],c2[1])
    
else:
    c = y-x
    
    c1 = (0,c)
    c2 = (-c,0)
    if(c2 < c1):
        c1,c2=c2,c1
    print(c1[0],c1[1],c2[0],c2[1])
    

