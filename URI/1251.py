from collections import Counter
cont = 0
while True:
    try:
        
        inp = [ord(i) for i in input()]

        if cont > 0:
            print()
            
        cont = 1
        dic = Counter(inp)
        
        a = sorted(dic, key = lambda x: (dic[x], -x))
        for i in a:
            print(i, dic[i])
        
    except EOFError:
        break
