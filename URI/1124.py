while True:

    l, c, r1, r2 = list(map(int, input().split()))

    x1 = r1
    y1= r1

    x2 = c-r2
    y2 = l-r2

    if sum([l,c,r1,r2]) == 0:
        break

    if r1*2 > l or r1*2 > c or r2*2 > l or r2*2>c:
        print("N")

    elif ((x1-x2)**2 + (y1-y2)**2)**(1/2) < r1+r2:
        print("N")
    else:
        print("S")
   
