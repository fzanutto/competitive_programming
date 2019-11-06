for u in range(int(input())):
    n = int(input())
    q = [int(i) for i in input().split()]
    q.sort(reverse=True)

    m = [0,0]
    for i,v in enumerate(q):
        if v>i:
            m = max(m, [i+1,i+1])
    print(m[0])        
