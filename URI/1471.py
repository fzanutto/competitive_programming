while True:
    try:
        x,y = map(int, input().split())
        
        chegaram = input().split()
        lista=[str(i) for i in range(1,x+1) if str(i) not in chegaram]
        if len(lista):
            print(' '.join(lista),"")
        else:
            print('*')
        
    except EOFError:
        break
