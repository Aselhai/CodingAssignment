income = int(input('Enter the taxable income in USD: '))

if income < 750:
    tax = income * 0.01
elif income < 2250:
    tax = 7.5 + (income-750) * 0.02
elif income < 3750:
    tax = 37.5 + (income-2250) * 0.03
elif income < 5250:
    tax = 82.5 + (income-3750) * 0.04
elif income < 7000:
    tax = 142.5 + (income-5250) * 0.05
else:
    tax = 230 + (income-7000) * 0.06

print('Tax due:', format(tax,'.2f'), 'USD')
