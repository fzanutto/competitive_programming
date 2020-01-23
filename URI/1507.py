for _ in range(int(input())):
    s = input()
    for i in range(int(input())):
        ind = 0
        q = input()
        for a in s:
            if a == q[ind]:
                ind += 1
            if ind == len(q):
                print('Yes')
                break
        else:
            print('No')
