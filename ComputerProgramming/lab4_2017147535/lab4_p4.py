a = int(input('Enter a number: '))
n = 1
answer = 0

while a % n != a:
    n = 10*n
    answer = answer + 1

if answer == 1:
    print('The number', a, 'contains', answer, 'digit')
else:
   print('The number', a, 'contains', answer, 'digits') 
