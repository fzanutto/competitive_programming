for _ in range(int(input())):
    n=int(input())
 
    conj = [int(i) for i in input().split() if int(i) <= 2048]
    conj.sort(reverse=True)
        
    if 2048 in conj:
        print('YES')
        continue
 
    if sum(conj) >= 2048:
        print('YES')
    else:
        print('NO')
