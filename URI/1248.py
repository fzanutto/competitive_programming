for i in range(0, int(input())):

    dieta = list(input())
    manha = list(input())
    almoco = list(input())

    try:
        list(map(lambda x: dieta.remove(x), manha))
        list(map(lambda x: dieta.remove(x), almoco))
        dieta.sort()
        print(''.join(dieta))
    except ValueError:
        print('CHEATER')
    
