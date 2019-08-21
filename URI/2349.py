n,c,s = map(int, input().split())
atual = 1
passagens = list(map(int,input().split()))

total = 0
if atual == s:
    total+=1

for i in passagens:
    atual+=i
    if atual<=0:
        atual = n
    elif atual > n:
        atual = 1
    if atual == s:
        total+=1
print(total)
