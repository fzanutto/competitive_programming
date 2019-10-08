a = 1
b = 1
soma = 0

while a < 40:
    soma += a/b
    a += 2
    b *= 2
    
print("%.2f" % soma)
