n = int(input('Enter an integer: '))
a = 0
l = 1

k = 0
while a < n:
    while  k < a:
        print(' ', end = '')
        k = k + 1
    k = 0
    while k < 2 * n - l:
        print('*', end = '')
        k = k + 1
    k = 0
    while k < a:
        print(' ', end = '')
        k = k + 1
    print('')
    k = 0
    a = a + 1
    l = l + 2
