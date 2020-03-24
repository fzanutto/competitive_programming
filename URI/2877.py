edras = []

grundy = {(x,0): 300 for x in range(101)}

for i in range(101):
    grundy[(i,i)] = 300
    grundy[(0,i)] = 300

def mex(l):
    m = 0
    l = list(set(l))
    l.sort()
    
    for i in l:
        if i != m:
            break
        
        m += 1
    return m

def calc(x,y):
    ans = []
    
    for i in range(1, min(x,y)+1):
        ans.append(grundy[(x-i,y-i)])
    
    for i in range(1, x+1):
        ans.append(grundy[(x-i,y)])    
    
    for i in range(1, y+1):
        ans.append(grundy[(x,y-i)])
        
    grundy[(x,y)] = mex(ans)
    return grundy[(x,y)]

for i in range(101):
    for j in range(101):
        if not grundy.get((i,j)):
            calc(i,j)
ans = 0

for _ in range(int(input())):
    a,b = [int(i) for i in input().split()]
    ans = ans ^ grundy[(a,b)]

if ans == 0:
    print('N')    
else:
   print('Y')

