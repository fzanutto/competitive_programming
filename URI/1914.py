for i in range(int(input())):
    a,b,c,d = input().split()
    x,y = [int(i) for i in input().split()]

    dic = {b:a, d:c}

    if (x+y) % 2 == 0:
        print(dic['PAR'])
    else:
        print(dic['IMPAR'])
