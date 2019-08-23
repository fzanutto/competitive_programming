n = int(input())
k = int(input())

pontos = [int(input()) for i in range(n)]

pontos.sort(reverse=True)


if k == n:
    print(k)
else:
    ultimo = pontos[k-1]
    pontos = pontos[k:]

    if ultimo in pontos:
        print(k + pontos.count(ultimo))
    else:
        print(k)
