code = int(input('Enter the first 12 digits of an EAN: '))

a = code // 10**11

b = code // 10**10
b = b % 10

c = code // 10**9
c = c % 10

d = code // 10**8
d = d % 10

e = code // 10**7
e = e % 10

f = code // 10**6
f = f % 10

g = code // 10**5
g = g % 10

h = code // 10**4
h = h % 10

i = code // 10**3
i = i % 10

j = code // 10**2
j = j % 10

k = code // 10**1
k = k % 10

l = code // 10**0
l = l % 10

odd = a + c + e + g + i + k
even = b + d + f + h + j + l

sum = even * 3 + odd
sum = 10 - sum
sum = sum % 10
sum = sum % 10

print('Check digit:', sum)
