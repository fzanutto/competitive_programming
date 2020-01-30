for _ in range(int(input())):
    n = int(input())
    
    l = [int(i) for i in input().split()]
    soma = 0
    for i in l:
        soma += i
        if soma <= 0:
            print('NO')
            break
    else:
        soma = 0
        for i in l[::-1]:
            soma += i
            if soma <= 0:
                print('NO')
                break
        else:
            print('YES')
            
            
    
