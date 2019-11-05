q = True
while True:    
    try:
        s = input()
        
        for i in s:
            if i == '"':
                if q:
                    print('``', end='')
                else:
                    print("''", end='')
                q = not q
            else:
                print(i, end='')
        print()
    except EOFError:
        break
