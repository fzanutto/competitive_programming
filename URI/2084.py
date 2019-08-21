input()

l = list(map(int, input().split()))
l.sort(reverse=True)

soma = sum(l)

if l[0] >= soma*0.45 or (l[0] >= soma*0.4 and l[0] >= l[1]+soma*0.1):
    print(1)
else:
    print(2)
