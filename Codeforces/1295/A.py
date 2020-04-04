for _ in range(int(input())):
    
    a = int(input())
    
    ans = list("1" * (a//2))
    
    
    if a % 2 == 1:
        ans[0] = '7'
    print(*ans,sep='')
