value = float(input('Enter a number: '))
compare = value
if value > 0:
    while value > 0:
        value = float(input('Enter a number: '))
        if value > compare:
            compare = value
        else:
            end = ''
    print('The largest number entered was', format(compare, '.2f'))
else:
    print('No positive number was entered')
