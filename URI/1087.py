while True:
    x,y,a,b = list(map(int, input().split()))

    if x+y+a+b == 0:
        break

    if x == a and y == b:
        print(0)
    elif x == a or y == b or (abs(x-a) == abs(y-b)):
        print(1)
    else:
        print(2)
