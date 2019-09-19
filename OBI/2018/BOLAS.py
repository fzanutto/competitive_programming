from collections import Counter
bolas = input().split()

cont = Counter(bolas)

for i in cont.values():
    if i > 4:
        print('N')
        break

else:
    print('S')
