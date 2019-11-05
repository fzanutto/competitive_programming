s = input()

def pa(ai, an, n):
    #print(ai,an,n)
    s = (ai+an)*n//2
    #print('pa',s) 
    return s


c = []
ant = s[0]
cont = 1
for i in s[1:]:
    if i != ant:    
        c.append((cont, ant))
        ant = i
        cont = 1
    else:   
        cont += 1
        
c.append((cont, ant))

soma = 0

for x in range(len(c)):
    i = c[x]
    if i[1] == '<':
        soma += pa(0, i[0]-1, i[0])
    else:
        soma += pa(i[0], 1, i[0])
        if x>0:
            off = max(0, c[x-1][0] - i[0])
            #print('off',off)
            soma += off

if c[-1][1] == '<':
    soma += c[-1][0]
    
print(soma)

