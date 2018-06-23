a = 1
sum = 0

while a != 0:
    a = int(input('Your number: '))
    if a > 100:
        end = ''
    else:
        sum = sum + a
    
print('sum:', sum)
