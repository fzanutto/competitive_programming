input()
l = [int(i) for i in input().split()]

l = list(set(l))
l.sort()
if len(l) > 1:
    print(l[1])
else:
    print('NO')
