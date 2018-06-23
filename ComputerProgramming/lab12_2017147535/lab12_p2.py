def moderateDays(mydict):
    lst = []
    for k in mydict:
        if 70 <= mydict[k] and mydict[k] <= 79:
            lst.append(k)
    return lst
