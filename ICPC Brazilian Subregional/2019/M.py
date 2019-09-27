def check(seg, pipocas):
    # seg = segundos para a equipe comer todas as pipocas

    por_pessoa = seg * t
    temp = 0
    i = 0
    
    for x in range(c):
        temp = 0
        while i < len(pipocas):
            if temp + pipocas[i] > por_pessoa:
                break
            temp += pipocas[i]
            i += 1
        
        
    return i == len(pipocas)

n,c,t = [int(i) for i in input().split()]

pipocas = [int(i) for i in input().split()]


l = 1
r = 10**9+1 # ver qnt pode ser o max de segundos possivel
while l < r:
    mid = (l+r)//2

    if check(mid, pipocas):
        r = mid
    else:
        l = mid + 1
        
print(l)
