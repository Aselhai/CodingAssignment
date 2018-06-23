def countAllLetters(line):
    # 문자열을 소문자로 변환후 리스트로 변환
    line = line.lower()
    line = list(line)

    # 영어 소문자 리스트 lst1 선언
    lst1 = []

    for k in range(97, 122 + 1):
        lst1.append(chr(k))

    # (소문자, 갯수)를 나타내는 lst2 선언
    lst2 = []

    for k in range(len(lst1)):
        if line.count(lst1[k]) != 0:
            lst2.append((lst1[k], line.count(lst1[k])))
    
    return lst2
        
