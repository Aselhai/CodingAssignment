isbn = input('Enter an ISBN: ')

list = isbn.split('-')

def Z(x):
    n = 0
    for n in range (0, ):
        if 10**(n) <= x and x < 10**(n + 1):
            pass
        else:
            n = n + 1
    return n
    
print('{0:.<20}'.format(str(list[0])) + 'GS1 prefix')
print('{0:.<20}'.format(str(list[1])) + 'Group identifier')
print('{0:.<20}'.format(str(list[2])) + 'Publisher code')
print('{0:.<20}'.format(str(list[3])) + 'Item number')
print('{0:.<20}'.format(str(list[4])) + 'Check digit')
