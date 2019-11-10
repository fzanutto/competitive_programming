n = int(input())
l = [int(i) for i in input().split()]


M = max(l)
m = min(l)

res = 0

I = l.index(M)
i = l[::-1].index(m)

if I > n-i-1:
    res -= 1
    
res += I
res += i

print(res)
