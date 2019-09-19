i = int(input())
a = [int(a) for a in input().split()]
r1 = 0
r2 = 0
for i in a:
    if i < 50:
        r1 += 1
    elif i < 85:
        r2 += 1

print(r1,r2)
        
