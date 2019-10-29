def countbits(n):
    if n <= 0:
        return 0
    cont = 0
    while n:
        if (n & 1) == 1:
            cont+=1

        n = n >> 1
    return cont

n,p = [int(i) for i in input().split()]

for k in range(1, 32):

    if countbits(n-k*p) <= k <= n-k*p:
        print(k)
        break
else:
    print(-1)    

