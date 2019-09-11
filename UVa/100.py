from math import log
dp = {}
def conta(i,j):
    res = 0
    for x in range(i,j+1):
        n = x
        if n in dp:
            res = max(res, dp[n])
            continue
    
        cont = 1
        while n != 1:
           
            if n & n-1 == 0:
                cont += log(n, 2)
                break
            
            if n%2==1:
                n = 3*n + 1
            else:
                n//=2
            cont += 1
        res = max(res, cont)
        dp[n] = cont
    return int(res)

while True:
    try:
        i,j = [int(x) for x in input().split()]

        print(i,j,conta(i,j))

    except EOFError:
        break
