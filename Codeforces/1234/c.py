q = int(input())
HORIZONTAL = 1
VERTICAL = 2
for i in range(q):

    n = int(input())
    mapa = [None, None]
    mapa[0] = [int(i) for i in list(input())]
    mapa[1] = [int(i) for i in list(input())]
    
    x=0
    y=0
    mov = HORIZONTAL
    while True:
        if x == n and y == 1:
            print('YES')
            break
            
        if x>=n:
            print('NO')
            break
            
        atual = mapa[y][x]
        if atual == -1:
            print('NO')
            break
            
        #print('v:',atual, x,y)
        if atual <= 2:
            if mov == VERTICAL:
                print('NO')
                break
                
            mov = HORIZONTAL
        else:
            if mov == HORIZONTAL:
                mov = VERTICAL
            else:
                mov = HORIZONTAL

        mapa[y][x] = -1
        
        if mov == HORIZONTAL:
            x+=1
        elif mov == VERTICAL:
            if y == 0:
                y = 1
            else:
                y = 0
      
        

        
            
