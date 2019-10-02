while True:
    v1,v2,a,d = [int(i) for i in input().split()]

    if v1 | v2 | a | d == 0:
        break

    v1 = (v1+d-1)//d
    v2 = (v2+d-1)//d
        
    #print(v1,v2)
    if a == 3:
        print("%.1f" %(v1*100 / (v1+v2)))
    else:
        p = a/6
        q = (6-a)/6
        #print(v1,v2)
        #print(((1-(q/p)**v1))*100, (1 - (q/p)**(v1+v2)))
        print("%.1f" %(((1 - (q/p)**v1))*100 / (1 - (q/p)**(v1+v2))))
