from collections import Counter

a = input()

b = Counter(input())
ans = []

if b.get('n'):
    ans.extend(['1'] * b['n'])
    
ans.extend(['0'] * b['z'])

print(' '.join(ans))
