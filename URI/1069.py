for i in range(0, int(input())):
    cont = 0
    b = input()
    a = b.replace(".", "")
    while "<>" in a:
        cont += a.count("<>")
        a = a.replace("<>", "")
        
    print(cont)
