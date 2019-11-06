def check(n, casas):
    #print('n:',n)
    global T,N,street
    current = n
    time = T
    need = 0
    last_house = 0
    
    for ind, i in enumerate(street):
        time -= 1
        
        if i == 'S':
            current += 1
             
        elif i == 'H':
            need += 1
            if need == 1:
                last_house = ind
        
        if need > 0 and current >= need:
            #print('p',time, ind-last_house)
            current -= need
            casas -= need
            need = 0
                        
            if casas > 0:
                if (ind-last_house)*2 >= N-last_house-1:
                    time -= N-last_house-1 + N-ind-1
                    
                    return time >= 0
                    
                time -= (ind-last_house)*2
            else:
                time -= ind-last_house
                    
        #print('lugar:',i,ind,current, time, need, last_house)
        
        if casas == 0:
            break
        
    #print(time)
    return time >= 0 and casas == 0
    
N,T = [int(i) for i in input().split()]

street = input().rstrip('.')
N = len(street)
C = street.count('H')
S = street.count('S')
l = max(C-S, 0)
r = 500005
#print(N, C)
while l < r:
    mid = (l+r)//2
    if check(mid, C):
        r = mid
    else:
        l = mid + 1

print(l if l < 500005 else -1)
