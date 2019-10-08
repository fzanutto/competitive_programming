def primo(n):
    if n == 1:
        return False
        
    for i in range(2, int(n**(1/2))+1):
        if n%i == 0:
            return False
    return True

t = int(input())

for i in range(t):
    a = int(input())
    print(a,end=' ')
    if primo(a):
        print('eh primo')
    else:
        print('nao eh primo')
