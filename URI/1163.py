import math
g = 9.80665
pi = 3.14159
while True:
    try:
        h = float(input())
        p1,p2 = [int(x) for x in input().split()]

        for i in range(int(input())):
            a,v = [float(x) for x in input().split()]
            b = v*math.sin(a*pi/180)
            a_ = g/2
            t = (b + math.sqrt(b*b + 4*a_*h))/(2*a_)
            x = t*v*math.cos(a*pi/180)

            print("%.5f -> " %x, end='')
            if p1 <= x <= p2:
                print("DUCK")
            else:
                print('NUCK')
    except EOFError:
        break
