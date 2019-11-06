for u in range(int(input())):
    n = int(input())
    s = list(input())
    t = list(input())
    
    pos = []
    
    for i in range(n):
        if s[i] != t[i]:
            pos.append(i)
    if len(pos) != 2:
        print('No')
    else:
        s[pos[0]], t[pos[1]] = t[pos[1]],s[pos[0]]
        if s==t:
            print('Yes')
        else:
            print('No')

        
    
