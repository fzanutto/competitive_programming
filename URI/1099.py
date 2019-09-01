n = int(input())

for _ in range(n):
    x,y =[int(i) for i in input().split()]
    if y < x:
        x,y=y,x
    print(sum(i for i in range(x+1,y) if i%2==1))
