a,b = input().split()

if a == b:
    print(a+'1',b+'2')
elif int(a)+1 == int(b):
    print(a,b)
elif a=='9' and b == '1':
    print(9,10)
else:
    print(-1)
