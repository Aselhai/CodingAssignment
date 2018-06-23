def countLetters(line):
    lst = []
    a = 0
    
    # 리스트 lst에 대문자 넣기
    for k in range(65, 90 + 1):
        lst.append(chr(k))

    # 리스트 lst에 소문자 넣기
    for k in range(97, 122 + 1):
        lst.append(chr(k))
    
    # 알파벳 찾기
    for k in range(len(line)):
        if line[k] in lst:
            a = a + 1
    
    return a
