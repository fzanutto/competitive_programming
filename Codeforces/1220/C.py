s = input()

a = [-1] * len(s)
menor = 'z'

#preprocessar
for i,v in enumerate(s):
    if menor < v:
        a[i] = 1
    else:
        menor = v


for k in range(len(s)):
    if k == 0:
        print('Mike')

    elif a[k] == 1:
        print('Ann')
        
    else:
        print('Mike')
