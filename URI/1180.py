n = int(input())
l = [int(i) for i in input().split()]

print('Menor valor:', min(l))

print('Posicao:', l.index(min(l)))
