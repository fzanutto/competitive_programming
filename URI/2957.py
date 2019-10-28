n,d = [int(i) for i in input().split()]

dic = {i:0 for i in range(ord('a'), ord('z')+1)}

for i in range(n):
    nome = input().lower().replace(' ', '')

    dic[ord(nome[0])] = max(dic[ord(nome[0])], len(nome))


lista = list(dic.values())
lista.sort(reverse=True)

soma = 0
for i in range(min(d,len(lista))):
    soma += lista[i]
print(soma)