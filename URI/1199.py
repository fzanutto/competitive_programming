while True:
    x = input()
    
    if x.startswith('0x'):
        print(int(x,base=16))

    elif int(x) < 0:
        break
    else:
        a = hex(int(x))
        print('0x%s' %a[2:].upper())
