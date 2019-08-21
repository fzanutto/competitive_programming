for i in range(1, int(input())+1):
    n,k = map(int, input().split())
    pos = k-1
    h = [i for i in range(1,n+1)]
    while len(h) > 1:
        if pos >= len(h):
            pos %= len(h)
        h.pop(pos)
        pos+=k-1
        
    print("Case {}:".format(i),h[0])
