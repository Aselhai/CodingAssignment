# Find the cube root of a perfect cube:

x = int(input('Your number: '))
ans = 0
n = 1

while ans**2 < x:
    ans = ans + 1
if ans**2 != x:
    print('No matching pair of integers found')
else:
    print('root: ' + str(ans)+ ', pwr: 2')

ans = 0

while ans**3 < x:
    ans = ans + 1
if ans**3 == x:
    print('root: ' + str(ans)+ ', pwr: 3')

ans = 0

while ans**4< x:
    ans = ans + 1
if ans**4 == x:
    print('root: ' + str(ans)+ ', pwr: 4')

ans = 0

while ans**5 < x:
    ans = ans + 1
if ans**5 == x:
    print('root: ' + str(ans)+ ', pwr: 5')

