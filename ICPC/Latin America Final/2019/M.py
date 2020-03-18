n,x = [int(i) for i in input().split()]

l = [int(i) for i in input().split()]

ant = l[0]
m = 1
cont = 1
for i in range(1,n):
    if l[i] > ant + x:
        m = max(m, cont)
        cont = 1
    else:
        cont += 1
    ant = l[i]
m = max(m, cont)
print(m)


