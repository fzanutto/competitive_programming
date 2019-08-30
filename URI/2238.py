a,b,c,d = map(int, input().split())

for i in range(a,int(c**(1/2)),a):
    if i%b != 0 and d%i != 0 and c%i == 0:
        print(i)
        break
else:
    e = c//2
    if e%b != 0 and d%e != 0 and e%a == 0 and e%b != 0:
        print(e)
            
    elif c%b != 0 and d%c != 0 and c%a == 0 and c%b != 0:
        print(c)
        
    else:
        print(-1)
