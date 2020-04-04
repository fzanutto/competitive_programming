for _ in range(int(input())):
    
    n,m = [int(i) for i in input().split()]
    l = [int(i) for i in input().split()]
    
    soma = sum(l)
    media = soma / n
    
    sobra = 0
    
    for i in range(1,n):
        sobra += l[i]
    
    
    
    print(min(sobra+l[0], m))
