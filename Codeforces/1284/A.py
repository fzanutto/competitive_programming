n,m = [int(i) for i in input().split()]

s = input().split()
t = input().split()

q = int(input())

for i in range(q):
    y = int(input()) - 1
    print(s[y%n]+t[y%m])

