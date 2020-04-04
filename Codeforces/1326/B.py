n = int(input())
a = [-1] * n
x = [-1] * n
b = [int(i) for i in input().split()]

a[0] = b[0]
x[0] = 0

for i in range(1, n):

    x[i] = max(x[i-1], a[i-1])

    a[i] = b[i] + x[i]
print(*a)
