dic = {}

for i in range(0, int(input())):
    a = int(input())
    if a in dic:
        dic[a]+=1
    else:
        dic[a] = 1
lista = [x for x in dic.keys()]
lista.sort()
for a in lista:
    print("{} aparece {} vez(es)".format(a, dic[a]))

