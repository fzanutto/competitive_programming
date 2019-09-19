a = int(input())
res = 1
while a:
    if a & 1:
        res = res << 1
    a = a >> 1
print(res)
