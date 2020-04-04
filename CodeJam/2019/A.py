for _ in range(int(input())):
    n = input()
    
    ans = ['','']
    
    for i in range(len(n)-1, -1, -1):
        if n[i] == '4':
            ans[0] = '3' + ans[0]
            ans[1] = '1' + ans[1]
        else:
            ans[0] = n[i] + ans[0]
            ans[1] = '0' + ans[1]
    print("Case #{}: {} {}".format(_+1, int(ans[0]), int(ans[1])))
