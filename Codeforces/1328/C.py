for _ in range(int(input())):
    n = int(input())
    x = input()
    
    a = ''
    b = ''
    maior = False
    
    for ind,i in enumerate(x):
    
        if i == '2':
            if ind == 0 or maior == False:
                a += '1'
                b += '1'
            elif maior == 'b':
                a += '2'
                b += '0'
            else:
                a += '0'
                b += '2'
                    
        elif i == '0':
            a += '0'
            b += '0'
            
        elif i == '1':
            if maior != 'a':
                a += '1'
                b += '0'
                maior = 'a'
            else:
                a += '0'
                b += '1'
                maior = 'a'
    print(a)
    print(b)
