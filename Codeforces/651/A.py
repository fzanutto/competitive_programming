a,b = [int(i) for i in input().split()]

x = min(a,b)
y = max(a,b)
time = 0
while x > 0 and y > 0:

    if y > 2:
        if y & 1:
            a = y // 2
            y = 1
        else:
            a = (y-2) // 2
            y = 2
            
        time += a
        x += a

    if x > 2:
        if x & 1:
            a = x // 2
            x = 1
        else:
            a = (x-2) // 2
            x = 2
        y += a
        time += a
        
    if x <= 2 and y <= 2:
        time += max(y,x)//2
        x=0
        y=0

print(time)
