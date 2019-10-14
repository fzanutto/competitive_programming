for _ in range(int(input())):
    x,y = [int(i) for i in input().split()]
    
    res = x-y
    
    if res != 1:
        print('YES')
    else:
        print('NO')
