for _ in range(int(input())):
    a,b = [int(i) for i in input().split()]

    if a % b == 0:
        print('YES')
    else:
        print('NO')
