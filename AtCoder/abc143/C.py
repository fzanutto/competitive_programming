n = int(input())

s = input()

ant = s[0]
soma = 1
res = 1
for i in s[1:]:
    if i == ant:
        soma += 1
    else:
       res += 1
       ant = i

print(res)
