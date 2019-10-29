v = [[],[]]
for _ in range(15):
    n = int(input())
    
    v[n%2].append(n)
    
    if len(v[n%2]) == 5:
        if n%2 == 0:
            s = 'par'
        else:
            s = 'impar'
        
        for i,val in enumerate(v[n%2]):
            print('{}[{}] = {}'.format(s,i,val))

        v[n%2] = []

for i,val in enumerate(v[1]):
    print('{}[{}] = {}'.format('impar',i,val))

for i,val in enumerate(v[0]):
    print('{}[{}] = {}'.format('par',i,val))

