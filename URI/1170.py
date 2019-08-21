for i in range(0, int(input())):
    a = float(input())
    cont=0
    while a > 1:
        a /= 2
        cont+=1
    print(cont,"dias")
