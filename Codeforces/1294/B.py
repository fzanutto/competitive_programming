for _ in range(int(input())):
    n = int(input())
    
    caixas = []
    
    for i in range(n):
        caixas.append([int(x) for x in input().split()])
    
    caixas.sort()
    
    ans = ''
    cur = [0,0]
    for i in caixas:
        a = (i[0] - cur[0])
        b = (i[1] - cur[1])
        ans += 'R' * a
        ans += 'U' * b
        
        if a < 0 or b < 0:
            ans = 'NO'
            break
        
        
        cur = i
    if ans != 'NO':
        print('YES')    
    print(ans)
