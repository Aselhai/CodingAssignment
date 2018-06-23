# 인삿말
print('This program can determine if a given string is a palindrome\n')
print('(Enter return to exit)')

# 입력값 받고 lst1에 저장
chars = input('Enter string to check: ')

while chars != '':
    lower = chars.lower()
    lst1 = list(lower)

    # lst1의 역순을 lst2로 정의
    lst2 = list(lst1)
    lst2.reverse()

    # 결과값 출력
    if lst1 == lst2:
        print(chars, 'is a palindrome\n')
    else:
        print(chars, 'is NOT a palindrome\n')

    #계속 입력값 받기
    chars = input('Enter string to check: ')
