notas = [50,10,5,1]

cont = 1
while True:
    x = int(input())
    if x == 0:
        break

    print("Teste",cont)
    cont+=1
    res = []
    for n in notas:
        numero = x//n
        x %= n
        res.append(str(numero))
    print(' '.join(res))
    print()
    
    
    
