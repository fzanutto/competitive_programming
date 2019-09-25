def calc(add, pos):

    if dp[add][pos] != -1:
       return dp[add][pos]

    if pos == n:
        dp[add][pos] = 0
        return 0

    dp[add][pos] = float('inf')

    for x in range(0,3):
        if pos == 0 or (a[pos]+x != a[pos-1] + add):
            dp[add][pos] = min(dp[add][pos], calc(x, pos+1) + x * b[pos])
            
    return dp[add][pos]


q = int(input())

dp = [[-1] * 300001 for l in range(3)]
a = [0] * 300001
b = [0] * 300001

for _ in range(q):
    n = int(input())
    
    for p in range(n):
        x,y = [int(i) for i in input().split()]
        a[p] = x
        b[p] = y
        dp[0][p] = -1
        dp[1][p] = -1
        dp[2][p] = -1

    print(calc(0,0))




