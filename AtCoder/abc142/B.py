n,k = [int(i) for i in input().split()]

ami = [int(i) for i in input().split()]
a = 0
for i in ami:
    if i >= k:
        a += 1
        
print(a)
