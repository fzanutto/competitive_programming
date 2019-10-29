def fib(n):

    if n == 0: return 0
    if n == 1: return 1
    
    v = [0,1]
    
    for i in range(n-1):
        temp = v[1]
        v[1] += v[0]
        v[0] = temp

    return v[1]
    
    
for i in range(int(input())):
    a = int(input())
    print('Fib({}) = {}'.format(a, fib(a)))
