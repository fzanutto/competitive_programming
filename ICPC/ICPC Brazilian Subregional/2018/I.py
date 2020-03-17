x = input().split()

inte = int(x[0])
lampadas = [False] * int(x[1])


acessas = input().split()[1:]
for i in acessas:
    lampadas[int(i)-1] = True
bkp = lampadas[:]

interruptores = []
for i in range(0, inte):
    temp = list(map(int, input().split()))
    interruptores.append(temp[1:])


cont = 0

while True in lampadas:
    
    if cont>0 and cont % inte == 0 and lampadas == bkp:
        cont = -1
        break

    for i in interruptores[cont%inte]:
        lampadas[i-1] = not lampadas[i-1]

    cont+=1

print(cont)
