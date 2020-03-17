from math import ceil

v,n = [int(i) for i in input().split()]
tot = v*n
for i in range(1,9):
    print(ceil(i*tot/10), end=' ')

print(ceil(9*tot/10))
