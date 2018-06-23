name = input('Enter a name (q to quit): ')
ans = 0

while name != 'q':
    n = 0
    while n < len(name):
        if 'a' in name[n]:
            ans = ans + 1
            n = n + 1
            continue
        elif 'A' in name[n]:
            ans = ans + 1
            n = n + 1
            continue
        else:
            n = n + 1
    name = input('Enter a name (q to quit): ')
    continue

print("Appearance of letter 'a':", ans)
