for _ in range(int(input())):
    n = int(input())
    escadas = [i+1 for i,v in enumerate(input()) if v == '1']
    
    res = 0
    if escadas:
        res = max(escadas[-1]*2, (n-escadas[0]+1)*2)
    print(max(res, n))
