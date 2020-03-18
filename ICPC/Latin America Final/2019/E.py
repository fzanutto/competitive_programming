bolo = input()
n = len(bolo)
s = int(input())
 
soma = 0
 
bolo += bolo[0:s-1]
 
 
indices = [0]*len(bolo)
ind = 1000000
 
for i in range(len(bolo)-1,-1, -1):
    if bolo[i] == 'E':
        ind = i
    else:
        if ind - i < s:
            indices[i] = ind-i
 
 
cont = 0
for i in range(n):
 
    if indices[i] == 0 and bolo[i] == 'P':
        continue
    
    soma += s
    
    if bolo[i] == 'P':
        soma -= indices[i]
 
print(soma)
