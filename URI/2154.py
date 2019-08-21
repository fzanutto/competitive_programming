while True:
    try:
        x = int(input())

        pol = input().split(' + ')

        res = []
        
        for p in pol:
            a=p.split('x')
            j,k = map(int, a)
            a[0] = str(j*k)
            a[1] = str(k-1)
            r = 'x'.join(a)
            if a[1]=='1':
                r=r[:-1]

            res.append(r)
        print(' + '.join(res))

    except EOFError:
        break
