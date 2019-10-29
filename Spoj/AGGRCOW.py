def check(x):
    cows = c - 1
    anterior = stalls[0]
    i = 1

    while cows and i < len(stalls):
        if stalls[i] - anterior >= x:
            cows -= 1
            anterior = stalls[i]
        i += 1
        
    return cows == 0  

for _ in range(int(input())):
    
    n,c = [int(i) for i in input().split()]

    stalls = []
    for i in range(n):
        stalls.append(int(input()))

    stalls.sort()

    l = 1
    r = stalls[-1]

    while l < r:
        mid = (l+r+1)//2

        if check(mid):
            l = mid
        else:
            r = mid - 1
            
    print(l)
