inter = 0
gremio = 0
emp = 0
while True:
    i,g = [int(i) for i in input().split()]

    if i > g:
        inter+=1
    elif g > i:
        gremio += 1
    else:
        emp += 1
    print('Novo grenal (1-sim 2-nao)')
    x = int(input())
    if x == 2:
        break
print(inter+gremio+emp, "grenais")
print('Inter:%d' %inter)
print('Gremio:%d' %gremio)
print('Empates:%d' %emp)

if inter > gremio:
    print('Inter venceu mais')
elif g > i:
    print('Gremio venceu mais')
else:
    print('Nao houve vencedor')
