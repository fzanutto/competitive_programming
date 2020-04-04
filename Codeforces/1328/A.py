for _ in range(int(input())):
    a,b = [int(i) for i in input().split()]
    
    if a < b:
        ans = b-a
    else:
        ans = (b - (a % b)) % b
    
    print(ans)
    



