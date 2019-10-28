res = []
while True:
    try:
        
        a = input()
        b = input()

        if a in b:
            res.append('verdadeira')
        else:
            res.append('falsa')
    except EOFError:
        break
        
for i,v in enumerate(res):
    print('Instancia', i+1)
    print(v)
    if i < len(res)-1:
        print()
