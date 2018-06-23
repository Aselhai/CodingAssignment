name = (input('Enter a first and last name: '))

e = len(name)
a = 0

while ' ' in name[a]:
    a = a + 1

b = a + 1

while ' ' not in name [b]:
    b = b + 1

c = b + 1

while ' ' in name[c]:
    c = c + 1

d = e - 1

while ' ' in name[d]:
    d = d - 1

print(str(name[c:d+1]) + ', ' + str(name[a]) + '.' )
