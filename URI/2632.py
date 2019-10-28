raios = {
    'fire': [20,30,50],
    'water': [10,25,40],
    'earth': [25,55,70],
    'air': [18,38,60]
}
danos = {'fire': 200, 'water': 300, 'air': 100, 'earth': 400}

for i in range(int(input())):
    w,h,x0,y0 = [int(x) for x in input().split()]

    tipo, lvl, cx,cy = [x for x in input().split()]
    lvl = int(lvl)-1
    cy = int(cy)
    cx = int(cx)

    raio = raios[tipo][lvl]

    if (x0-cx)**2 + (y0-cy)**2 <= raio**2:
        print(danos[tipo])
    elif (x0-cx)**2 + (y0+h-cy)**2 <= raio**2:
        print(danos[tipo])
    elif (x0+w-cx)**2 + (y0-cy)**2 <= raio**2:
        print(danos[tipo])
    elif (x0+w-cx)**2 + (y0+h-cy)**2 <= raio**2:
        print(danos[tipo])
    # aaaa
    elif cx-raio <= x0 <= cx+raio and y0 <= cy <= y0+h:
        print(danos[tipo])
    elif cx-raio <= x0+w <= cx+raio and y0 <= cy <= y0+h:
        print(danos[tipo])
    elif cy-raio <= y0 <= cy+raio and x0 <= cx <= x0+w:
        print(danos[tipo])
    elif cy-raio <= y0+h <= cy+raio and x0 <= cx <= x0+w:
        print(danos[tipo])
    elif x0 <= cx <= x0+w and y0 <= cy <= y0+h:
        print(danos[tipo])
    else:
        print(0)
