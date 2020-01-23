import sys
chave = input()
l = len(chave)
n = int(input())

for _ in range(n):
    
    cont = 0
    frase = sys.stdin.readline().split()

    final = ""
    alfabeto = "abcdefghijklmnopqrstuvwxyz"
    cont2 = 0
    
    mapa = {"a": 1, "b": 2, "c": 3, "d": 4, "e": 5, "f": 6, "g": 7, "h": 8, "i": 9, "j": 10, "k": 11, "l":12, "m":13, "n":14, "o":15, "p":16, "q":17, "r":18, "s":19, "t":20, "u":21, "v":22, "w":23, "x":24, "y":25, "z":26}
    
    for palavra in frase:
        if palavra[0].lower() not in ["a", "e", "i", "o", "u"]:
            for letra in palavra:
                x = mapa[chave[cont2%l]]

                y = mapa[letra]
                t = int((x + y - 1) % 26)
                #print(chave[cont2%l], cont2, cont2%l,x,y, alfabeto[t-1])

                final += alfabeto[t-1]
                
                cont2 += 1
            
            final += " "

        else:
            final += palavra + " "
         
    sys.stdout.write(final)
    sys.stdout.write("\n")
