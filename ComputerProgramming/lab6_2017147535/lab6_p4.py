L = 1


while L != 0:
    L = int(input('Enter the limit L: '))
    if L != 0:
        b = 0
        for a in range(1, L+1):
            b = b + (1/a)
        print('Sum of the initial', L, 'term(s):', format(b, '.6f')) 
    else:
        exit = ''
