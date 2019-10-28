n,g = [int(i) for i in input().split()]
runas = {}
for i in range(n):
    r,v = [x for x in input().split()]
    runas[r] = int(v)


input()
r = input().split()
soma = sum(runas[i] for i in r)
print(soma)
if soma < g:
    print('My precioooous')
else:
    print('You shall pass!')