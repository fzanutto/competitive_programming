for _ in range(3):
    soma = 0
    s = input()
    while s != 'caw caw':
        s = s.replace('-', '0').replace('*','1')
        soma += int('0b'+s, 2)
        s = input()
        
        
    print(soma)
    
