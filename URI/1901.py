floresta = []
v = int(input())
for i in range(0, v):
    x = input()
    floresta.append(x.split())
tot = []
for i in range(0, 2*v):
    x,y=map(int, input().split())
    tot.append(floresta[x-1][y-1])

print(len(set(tot)))
