while True:

    ans = []
    
    n,k,m = [int(i) for i in input().split()]
    if n == 0:
        break

         
    lista = list(range(1,n+1))

    
    p = (k-1)%len(lista)
    s = ((n-1)+(len(lista)-(m-1))) % len(lista)
    
    while True:
        #print(p,s)
        
        if s != p:
            e1 = lista[p]
            e2 = lista[s]
            
            ans.append("{:>3}{:>3}".format(e1,e2))
          
            lista.remove(e1)
            lista.remove(e2)
            
            if p>s:
                p-=1
            else:
                s-=1
        
        else:
            ans.append("{:>3}".format(lista[p]))
            lista.remove(lista[p])
            
        t = len(lista)
        
        if not t:
            break
            
        p = (p+k-1) % t
        s = (s-m) % t
  

    print(*ans, sep=',')
