for u in range(int(input())):
    n = int(input())
    s = list(input())
    t = list(input())
    
    pos = []

    for i in range(n):
        if s[i] != t[i]:
            for j in range(i+1, n):
                if t[i] == t[j]:

                    s[i], t[j] = t[j], s[i]
                    pos.append([i+1,j+1])

                    break
                
                elif t[i] == s[j]:
                    t[j], s[j] = s[j],t[j]
                    pos.append([j+1,j+1])
                    
                    s[i],t[j] = t[j],s[i]
                    pos.append([i+1,j+1])

                    break
            
    if s == t and len(pos) <= 2*n:
        print('Yes')
        print(len(pos))
        for i in pos:
            print(*i)
    else:
        print('No')
        

