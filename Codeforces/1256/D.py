for _ in range(int(input())):
    n,k = [int(i) for i in input().split()]
    
    s = input()
    
    cont = 0
    bit = 0
    zeros = []
    
    for i in range(n):
        if s[i] == '0':
            zeros.append(i)

    for i,v in enumerate(zeros):
        #print()
        #print(k,v,bit)
        if k > v-bit:
           a = v-bit
           k -= a
           print('0', end='')
           bit += 1
        else:
            falta = (v-bit) - k
            bit += 1
            for x in range(falta):
                print('1',end='')
            print('0',end='')
            
            for x in range(v-falta-bit+1):
                print('1',end='')
            v+=1
            while v < n:
                print(s[v],end='')
                v += 1
            break
    
    else:
        print('1'*(n-len(zeros)),end='')
        
    print()
            
        
