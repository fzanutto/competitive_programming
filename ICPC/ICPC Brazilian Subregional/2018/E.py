a = input()
b = input()

dif = len(a) - len(b)
ans = 0

for i in range(dif + 1):

    for j in range(len(b)):

        if a[j+i] == b[j]:    
            break
    else:
        ans += 1
print(ans)
