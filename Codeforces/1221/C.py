def check(c, m, x, num):
    if num == 0:
        return True
    if num > c or num > m:
        return False

    c -= num
    m -= num
    
    if num > c+m+x:
        return False

    return True

for _ in range(int(input())):
    c,m,x = [int(i) for i in input().split()]
    
    l=0
    r = max(c,m)
    
    while(l < r):
        mid = (l+r+1) // 2
        
        if check(c, m, x, mid):
            l = mid
        else:
            r = mid - 1
    if check(c,m,x,l):
        print(l)
    else:
        print(0)
