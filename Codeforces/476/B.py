a = input()
b = input()

correct = 0
for i in a:
    if i == '+':
        correct += 1
    else:
        correct -= 1

run = 0
doubt = 0
for i in b:
    if i == '+':
        run += 1
    elif i == '-':
        run -= 1
    else:
        doubt += 1


if doubt == 0:
    if run == correct:
        print(1)
    else:
        print(0)
else:
    mask = (1<<doubt) - 1

    correct_trial = 0

    while mask >= 0:
        c = mask
        temp = run
        for j in range(doubt):
            if c&1:
                temp += 1
            else:
                temp -= 1
            c >>= 1
        if temp == correct:
            correct_trial+=1
            
        mask -= 1   
            
    print(correct_trial / (1<<doubt))
      
