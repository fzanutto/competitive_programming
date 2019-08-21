x = input().split()
tamanho = int(x[0])

posicoes = [int(i) for i in input().split()]

dif = 0
for i in range(len(posicoes)-1):
    temp = posicoes[i+1] - posicoes[i]
    if temp > dif:
        dif = temp

dif = dif//2


print(max(posicoes[0]-1, tamanho-posicoes[-1], dif))
