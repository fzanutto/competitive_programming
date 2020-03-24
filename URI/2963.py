n = int(input())
a = int(input())
ok = 1
for i in range(n-1):
    if int(input()) > a:
        ok = 0
if ok:
    print('S')
else:
    print('N')

