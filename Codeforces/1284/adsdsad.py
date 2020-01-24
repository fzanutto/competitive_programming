for _ in range(int(input())):
    a = list(input())
    
    a.sort()
    temp = 0
    for i in range(len(a)):
        if a[i] != '0':
            print(a[i],end='')
            temp = i
            break
    for i in range(len(a)):
        if i != temp:
            print(a[i], end='')
    print()   
