def solve(n, num):

    isEven = (int(num[-1]) % 2) == 0
    
    isSumEven = (sum([int(i) for i in num]) % 2) == 0
    
    if not isEven and isSumEven:
        return num
    
    if isEven:
        #numero par -> tirar o ultimo digito até ter um numero impar
        ind = n-1
        while int(num[ind]) % 2 == 0:
            ind -= 1
            if ind == -1:
                return -1
        
        num = num[:ind+1]

    # a partir daqui é impar
    
    isSumEven = sum([int(i) for i in num]) % 2 == 0
    
    if isSumEven:
        return num
    
    ind = 0
    ans = ""
    # tirar um numero impar do meio do numero 
    while ind < len(num)-1:
        if int(num[ind]) % 2 == 1:
            break
        else:
            ans += num[ind]
        ind += 1
    
    if ind == len(num) - 1:
        return -1
        
    
    ans += num[ind+1:]
    
    if sum([int(i) for i in ans]) % 2 == 0:
        return int(ans)
    else:
        return -1
    
    



for _ in range(int(input())):
    n = int(input())
    
    num = input()
    
    print(solve(n, num))
