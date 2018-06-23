x = int(input('Enter a value for x: '))

def evalPolynomial(x):
    return 3*(x**5)+2*(x**4)-5*(x**3)-(x**2)+7*x-6

print('Polynomial for x=' + str(x) + ': ' + str(evalPolynomial(x)))
