def formatMonth(date):
    date = list(date)

    for k in range(len(date)):
        if date[k] == '/':
            date[k] = '-'
    ans = ''
    
    for k in range(len(date)):
        ans = ans + date[k]
    return ans
