from math import factorial
while True:
    try:
        n,m = [int(i) for i in input().split()]
        print(factorial(n) + factorial(m))
    except EOFError:
        break
