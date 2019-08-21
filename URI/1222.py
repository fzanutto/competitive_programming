from math import ceil
while True:

    try:
        n,l,c = map(int, input().split())
        frase = input().split()

        espacos = 0
        linhas = 0
        temp = ''
        for i in frase:
            espacos += len(i) + 1
            temp += i + ' '
            if espacos - 1 > c:
                temp = i + ' '
                espacos = len(i) + 1
                linhas+=1
        linhas+=1
        print(ceil(linhas/l))

    except EOFError:
        break
