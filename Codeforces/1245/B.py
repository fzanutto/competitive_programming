from collections import Counter
t = int(input())
for _ in range(t):
    n = int(input())
    
    need = (n+1)//2
    
    # R P S
    disp = [int(i) for i in input().split()]
    
    ganha = {'R':1, 'P':2,'S':0}
    dic = {0:'R', 1:'P', 2:'S'}
    jog = input()
    
    res = []
    i = 0
    while i < len(jog):
        if need and disp[ganha[jog[i]]]:
            disp[ganha[jog[i]]] -= 1
            res.append(dic[ganha[jog[i]]])
            need -= 1
        else:
            res.append('*')
        i += 1
        

    if need == 0:
        print('YES')
        
        for i in res:
            if i != '*':
                print(i, end='')
            else:
                if disp[0]:
                    print('R',end='')
                    disp[0] -= 1
                elif disp[1]:
                    print('P', end='')
                    disp[1] -= 1
                elif disp[2]:
                    print('S', end='')
                    disp[2] -= 1
        print()
    else:
        print('NO')
   
    
