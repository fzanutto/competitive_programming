d,i,x,f = [int(i) for i in input().split()]

for a in range(1,f+1):
    if (d + a)% 2 == 0:
        i += x
    else:
        i -= x
print(i)
