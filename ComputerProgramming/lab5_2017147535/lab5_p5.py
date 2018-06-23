f = input('Enter a fraction: ')

o = 0
r = len(f) - 1
s = 0

while '/' not in f[s]:
    s = s + 1
    
while ' ' in f[o]:
    o = o + 1

p = o + 1

while ' ' not in f[p]:
    p = p + 1

q = s + 1

while ' ' in f[q]:
    q = q + 1


a = int(f[o:p])
b = int(f[q:])
a1 = int(f[o:p])
b1 = int(f[q:])


if a == 1:
    print('In lowest terms: ' + str(a) + '/' + str(b))
else:
    while b % a  != 0:
        c = b % a
        b = a
        a = c
    print('In lowest terms: ' + str(int(a1 / a)) + '/' + str(int(b1 / a)))

