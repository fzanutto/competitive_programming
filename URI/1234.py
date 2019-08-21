while True:
    try:

        frase = list(input())
        anterior_maiusculo = False
        
        for i,v in enumerate(frase):
            if v == ' ':
                continue

            if v.isupper() == anterior_maiusculo: #se o anterior o atual tem o msm "tipo"
                frase[i] = v.swapcase()
                
            anterior_maiusculo = not anterior_maiusculo
        print(''.join(frase))
    except EOFError:
        break
    
