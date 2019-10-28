from math import factorial
def n(k,d):

    return (k**(d+1) - 1) / (k-1)
    
    
def f(k,d):
    if d == 0: 
        return 1
    if d == 1:
        return factorial(k)
    if k == 1:
        return 1
        
    return factorial(n(k,d)-1) * f(k, d-1)**k // factorial(n(k,d-1))**k 
    
    
    
while True:
    try:
        a,b = [int(i) for i in input().split()]
        
        print(f(a,b))
    except EOFError:
        break
