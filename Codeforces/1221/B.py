x = int(input())
for i in range(x):
    for j in range(x):
        if (j+i) % 2 == 0:
            print('W', end='')
        else:
            print('B', end='')
    print()
