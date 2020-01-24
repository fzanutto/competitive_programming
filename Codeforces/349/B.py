def main():
    n = int(input())
    l = [int(i) for i in input().split()]

    m = [max(l),0]
    pos = 0
    for i,v in enumerate(l):
        if v<=m[0]:
            m=[v,str(i+1)]

    max_digits = n//m[0]
    resto = n - max_digits*m[0]
    if not max_digits:
        print(-1)
        return
        
    for i in range(max_digits):
        v = -1
        for num in range(int(m[1]), 9):
            if resto >= l[num] - m[0]:
                v = num

        if v == -1:
            print(m[1]*(max_digits-i))
            break
        else:
            resto -= l[v] - m[0]
            print(v+1, end='')
    else:
        print()
main()
