v = []

for x in range(20):
    v.append(int(input()))
for x in range(20):
    print('N[{}] = {}'.format(x, v[19-x]))

