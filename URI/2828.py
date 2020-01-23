from math import factorial
from collections import Counter

palavra = input()
dic = {}
cont = Counter(palavra)

resultado = factorial(len(palavra))
    
for ii,i in cont.items():
    
    if i not in dic:
        a = factorial(i)
        dic[i] = a
    else:
        a = dic[i]
    resultado /= a
    
print(int(resultado % ((10**9)+7)))
