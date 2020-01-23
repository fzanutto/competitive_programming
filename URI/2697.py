x,y = [int(a) for a in input().split()]

n = [int(i) for i in input().split()]
numeros = [int(i) for i in set(n)]
quant = [n.count(i) for i in numeros]

lista_numeros = [0]*x
for i in n:
    lista_numeros[i-1]+=1


quant1 = quant[:]
quant2 = quant[:]
quant3 = quant[:]

maior_quant = max(quant)
menor_quant = min(quant)

pos_maior = quant.index(maior_quant)
pos_menor = quant.index(menor_quant)

quant1[pos_maior] -=1
quant2[pos_menor] += 1
quant3[pos_menor] += 1
quant3[pos_maior] -= 1

res = '*'
if 0 in lista_numeros:
    ind = lista_numeros.index(0)
    lista_numeros[ind] = 1
    if len(set(lista_numeros)) == 1:
        res = '+' + str(ind+1)

elif len(set(quant1)) == 1:
    res = "-{}".format(numeros[pos_maior])
elif len(set(quant2)) == 1:
    res = "+{}".format(numeros[pos_menor])
elif len(set(quant3)) == 1:
    res = '-{} +{}'.format(numeros[pos_maior], numeros[pos_menor])
else:
    res = '*'

print(res)
