# recieve v(hex)
a = input('Enter a color: ')
a = a.lower()

# use dic1 separate each number
dic1 = {}
for k in range(6):
    dic1[k] = a[k]

# dic 2 is for hex to dec
dic2 = {'a': 10, 'b': 11, 'c': 12, 'd': 13, 'e': 14, 'f':15}

# hex to dec
for k in range(6):
    if dic1[k] in dic2:
        dic1[k] = dic2[dic1[k]]

# calculate
v1 = int(dic1[0]) * 16 + int(dic1[1])
v2 = int(dic1[2]) * 16 + int(dic1[3])
v3 = int(dic1[4]) * 16 + int(dic1[5])

# print value!
print('Red:', v1)
print('Green:', v2)
print('Blue:', v3)
