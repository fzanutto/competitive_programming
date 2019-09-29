import sys
h,w = [int(i) for i in input().split()]

matriz = [[-1] * w for _ in range(h)]
r = [int(i) for i in input().split()]

c = [int(i) for i in input().split()]


for i,v in enumerate(r):
    if v == 0:
        matriz[i][0] = 0
    else:
        for x in range(v):
            matriz[i][x] = 1
        if x+1 < w:
            matriz[i][x+1] = 0

for i,v in enumerate(c):
    if v == 0:
        if matriz[0][i] == 1:
            print(0)
            sys.exit()
        matriz[0][i] = 0
    else:
        for x in range(v):
            if matriz[x][i] == 0:
                print(0)
                sys.exit()
            matriz[x][i] = 1
            
        if x+1 < h: 
            if matriz[x+1][i] == 1:
                print(0)
                sys.exit()
            matriz[x+1][i] = 0

      
temp = 0
for i in matriz:
    temp += i.count(-1)

print((2**temp) % (10**9+7))

