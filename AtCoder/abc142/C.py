n = int(input())

lista = [int(i) for i in input().split()]

res = []
for i,v in enumerate(lista):
    res.append((i,v))


res.sort(key= lambda x: x[1])

for i in res[:-1]:
    print(i[0]+1, end=' ')
    
print(res[-1][0]+1)
