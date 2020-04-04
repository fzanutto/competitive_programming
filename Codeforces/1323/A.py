for _ in range(int(input())):
    n = int(input())
    a = [int(i) for i in input().split()]
    
    par = []
    impar = []
    
    for i,v in enumerate(a):
        if v % 2 == 0:
            print(1)
            print(i+1)
            break
        else:
            impar.append(i+1)
            if len(impar) == 2:
                print(2)
                print(*impar)
                break
    else:
        print(-1)
