from math import log,ceil

def bitnot(n):
    if n == 0:
        return (1 << 31) - 1
    return (1 << 31) - 1 - n

#print(bitnot(4))
n = int(input())

l = [int(i) for i in input().split()]


f = bitnot(l[0])
prefix = []
for i in l:
    f &= bitnot(i)
    prefix.append(f)

f = bitnot(l[-1])
sufix = []
for i in l[::-1]:
    f &= bitnot(i)
    sufix.append(f)

#print(l)  
#print(prefix)
#print(sufix)
    
m = [-1,-1]

for i in range(n):
    
    first = l[i]
    
    p = s = 2**31 - 1
    
    if i > 0:
        p = prefix[i-1]
        
    if i < n-1:
        s = sufix[n-i-2]
    
    #print(p,s)
    r = (p & s)
    
    #print('ands:', r)
    
    ans = first & r
    
    #print('ans:', first, ans)
    if ans > m[0]:
        m[0] = ans
        m[1] = i

l[m[1]],l[0] = l[0], l[m[1]]

print(*l)
