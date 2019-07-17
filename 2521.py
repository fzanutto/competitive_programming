from math import sin, cos, pi

while True:

    try:
        r, la, lo = [int(i) for i in input().split()]


        y = sin(la * pi / 180) * r
        
        x = sin(lo * pi / 180) * r * cos (la * pi / 180)
        z = -cos(lo * pi / 180) * r * cos (la * pi / 180)

        if abs(x) < 10**-16:
            x=0
        
        if abs(y) < 10**-16:
            y=0

        if abs(z) < 10**-16:
            z=0

        print("{:.2f} {:.2f} {:.2f}".format(x,y,z))

    except EOFError:
        break
