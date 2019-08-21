import math

primo = [2,3]
def e_primo(num):
    if num in primo:
        return True
    if num == 1 or num == 0:
        return False
    cont=2
    while cont <= math.sqrt(num):
        if num % cont == 0:
            return False
        cont+=1
    
    primo.append(num)
    return True

while True:
    try:
        x = input()
        n = int(x)
        cl = 0

        if e_primo(n):
            cl+=1

            for i in x:
                if not e_primo(int(i)):
                    break
            else:
                cl+=1

        if cl == 0:
            print("Nada")
        elif cl == 1:
            print("Primo")
        elif cl == 2:
            print("Super")
            
    except EOFError:
        break
