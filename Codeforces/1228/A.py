a,b = [int(i) for i in input().split()]

for i in range(a,b+1):
    if len(set(str(i))) == len(str(i)):
        print(i)
        break
else:
    print(-1)
