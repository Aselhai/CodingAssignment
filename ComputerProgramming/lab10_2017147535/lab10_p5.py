def extractMessage(err_msg):
    # 시작하는 a과 끝내는 b 지정
    a = 0
    b = len(err_msg) - 1

    # 반복문으로 ' ', '*'이 아닌 문자열 조
    while a < len(err_msg):
        if err_msg[a] != ' ' and err_msg[a] != '*':
            break
        a = a + 1
    while b > 0:
        if err_msg[b] != ' ' and err_msg[b] != '*':
            break
        b = b - 1
    
    return err_msg[a:b+1]

