ld, cd, lv, cv = [int(i) for i in input().split()]

res = 0



a = min(cd+cv, lv, ld)**2
b = min(ld+lv, cd, cv)**2

ld,cd = cd,ld

c = min(cd+cv, lv, ld)**2
d = min(ld+lv, cd, cv) **2

lv,cv = cv,lv

e = min(cd+cv, lv, ld)**2
f = min(ld+lv, cd, cv) **2


i = min(ld,cd)**2
j = min(lv,cv)**2

print(max(a,b,c,d,e,f, i, j))
