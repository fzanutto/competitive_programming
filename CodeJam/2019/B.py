def solve(case):
    n = int(input())
    s = input()
    ans = ''
    for i in s:
        if i == 'S':
            ans += 'E'
        else:
            ans += 'S'
    print("Case #{}:".format(case), ans)
    

for _ in range(int(input())):
    solve(_+1)
        
