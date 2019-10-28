n = int(input())
s = input()

res = (n*(n-1)) // 2

for i in range(2):
    cont = 1
    for a in range(1,n):
        if s[a] == s[a-1]:
            cont += 1
        else:
            res -= cont - i
            cont = 1
    s = s[::-1]
print(res)
