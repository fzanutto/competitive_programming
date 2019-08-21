while True:
    try:
        x=input() 
        if x=='0':
            break
        l = input().split()
        l2 = set()

        for i in l:
            if i in l2:
                l2.remove(i)
            else:
                l2.add(i)     
        a=l2.pop()
        b=l2.pop()
       
        if int(a) > int(b):
            print(b,a)
        else:
            print(a,b)
    except:
        break
