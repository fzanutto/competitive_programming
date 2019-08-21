estrelas = []
total = 0
roubados = 0
assaltadas = 0
n = int(input())

    
estrelas = list(map(int, input().split()))
copia = estrelas[:]
total = sum(estrelas)

i=0
while True:
    if estrelas[i]:
        roubados+=1
    
    if estrelas[i]%2 == 0:
        estrelas[i] = estrelas[i] - 1
        i-=1
    else:
        
        estrelas[i] = estrelas[i] - 1
        i+=1

    if i<0 or i >=n:
        break


for a in range(0,n):
    if estrelas[a] != copia[a]:
        assaltadas+=1

print(assaltadas, total-roubados)
