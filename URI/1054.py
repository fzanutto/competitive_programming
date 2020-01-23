for _ in range(int(input())):
    n, d = [int(i) for i in input().split()]
    
    pedras = {}
    
    for i in range(n):
        tipo, dist = input().split('-')
        pedras[int(dist)] = tipo
        
    ant = None
    for i in pedras:
        if ant == 'S' and pedras[i] == 'S':
            pedras[i] == -1
            ant = None
        else:
            ant = pedras[i]


    tot = 0
    ant = 0
    for i in pedras:
        if pedras[i] != -1:
            tot = max(tot, i-tot)
            ant = i
