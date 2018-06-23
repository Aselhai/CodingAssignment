def reduceWhitespace(line):
    line = line.split(' ')

    k = 0

    # NULL값을 찾고 찾았다면 line의 길이를 고려하여 k를 0으로 반환
    while k < len(line):
        if line[k] == '':
            del line[k]
            k = 0
        k = k + 1

    # 리스트를 문자열로 변환
    ans = ''
    
    for k in range(len(line)):
        ans = ans + line[k] + ' '
    
    return ans[0:len(ans) - 1]
