def s(i):
    return -i[0], -i[1], -i[2], i[3]
  
n = int(input())
paises = []
for i in range(n):
    n,o,p,b = [f for f in input().split()]
    
    paises.append([int(o),int(p),int(b),n])

paises.sort(key=s)

for i in paises:
    print(i[3], i[0], i[1], i[2])
