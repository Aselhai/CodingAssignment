a = str(input('Enter a sentence: '))

n1 = a.count('a')
n2 = a.count('e')
n3 = a.count('i')
n4 = a.count('o')
n5 = a.count('u')
n6 = a.count('A')
n7 = a.count('E')
n8 = a.count('I')
n9 = a.count('O')
n10 = a.count('U')

n = n1 + n2 + n3 + n4 + n5 + n6 + n7 + n8 + n9 + n10
if n == 1:
    print('Your sentence contains', n, 'vowel.')
else:
    print('Your sentence contains', n, 'vowels.')
