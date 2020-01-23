MOD = 86400

def exp(num, n):

    if n == 0: return 1
    if n == 1: return num
    
    res = exp(num, n>>1)
    res = (res * res) % MOD
    
    if n&1:
        res = (res * 2) % MOD
    
    return res

n = int(input())

    
res = exp(2,n)
res -= 1

segundos = res%60

minutos = res // 60
horas = minutos//60

minutos %= 60
horas %= 24

print("{:0>2}:{:0>2}:{:0>2}".format(horas,minutos,segundos))
