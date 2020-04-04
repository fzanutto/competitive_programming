

for _ in range(int(input())):
    n = int(input())
    a = [int(i) for i in input().split()]
    
    if sum(a) % 2 == 1:
        print('YES')
    
    
    else:
        par = False
        impar = False
        for i in a:
            if i % 2 == 0:
                par = True
            else:
                impar = True
        if par and impar:
            print('YES')
        else:
            print('NO')
            



