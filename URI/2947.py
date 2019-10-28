nq = int(input())

q = input().lower()

n = int(input())
alunos = []

for i in range(n):
    a = list(input().lower())

    for x in range(nq):
        if a[x] == q[x]:
            a[x] = -1

    alunos.append(a)
res = 0

for x in range(nq):
    dic = {i:0 for i in range(ord('a'), ord('z')+1)}

    for i in range(n):

        if alunos[i][x] != -1:
            dic[ord(alunos[i][x])] += 1
    res += max(dic.values())

print(res)