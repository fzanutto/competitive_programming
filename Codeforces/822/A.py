def fact(n):
    if n == 1:
        return 1
    
    return n * fact(n-1)

a,b = [int(i) for i in input().split()]

print(fact(min(a,b)))
