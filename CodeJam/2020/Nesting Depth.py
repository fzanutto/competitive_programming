def solve(case):
    s = input()
    
    ans = ''
    
    opening = 0
    
    for i in range(len(s)):

        dif = int(s[i]) - opening

        opening = int(s[i])
        
        if dif > 0:
            ans += '(' * dif
        elif dif < 0:
            ans += ')' * -dif
        
        ans += s[i]
    
    ans += ')' * int(s[-1])
    
    print("Case #{}:".format(case), ans)
    
for _ in range(int(input())):
    solve(_+1)
        
