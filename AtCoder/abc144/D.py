from math import atan, pi
a,b,x = [int(i) for i in input().split()]




ocupado = x/(a*a)



if ocupado == b:
    alfa = pi/2

elif ocupado*2 >= b:
    sobra = b - ocupado

    #alfa = atan(sobra/ocupado)
    alfa = atan(a / (2*(b-ocupado)))
else:
    alfa = atan((2*a*ocupado) / (b*b))
print("%.10f" %(90 - alfa*180/pi))
