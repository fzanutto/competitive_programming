for _ in range(int(input())):
    a = set(input())
    b = set(input())
    if b.intersection(a):
        print('YES')
    else:
        print("NO")
