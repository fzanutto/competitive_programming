for i in range(int(input())):
    a = input()
    if len(a) <= 10:
        print(a)
    else:
        print("{0}{2}{1}".format(a[0], a[-1], len(a)-2))
