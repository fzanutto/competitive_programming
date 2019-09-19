l1 = int(input())
l2 = int(input())

c1 = int(input())
c2 = int(input())

if l1 == l2:
    p1 = (l1+l2) * 2
elif abs(l1 - l2) == 1:
    p1 = (l1+l2) * 3
else:
    p1 = l1 + l2


if c1 == c2:
    p2 = (c1+c2) * 2
elif abs(c1 - c2) == 1:
    p2 = (c1+c2) * 3
else:
    p2 = c1 + c2

if p1 > p2:
    print('Lia')
elif p1 < p2:
    print('Carolina')
else:
    print('empate')
