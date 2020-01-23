op = ('*','/','+','-','^')
fila = []
pilha = []
for _ in range(int(input())):
    
    s = input()
    
    
    
    for i in range(len(s)):
        if s[i] in op:
            pilha.append(s[i])
        elif s[i] == '(':
            continue
        else:
            fila.append(s[i])
