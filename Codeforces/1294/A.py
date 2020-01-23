for _ in range(int(input())):
    a,b,c,n = [int(i) for i in input().split()]
    
    m = max(a,b,c)
    
    dif = m-a + m-b + m-c
    
    if n >= dif and (n-dif) % 3 == 0:
        print('YES')
    else:
        print('NO')

