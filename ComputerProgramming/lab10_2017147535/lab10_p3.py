def findAt(email_addr):
    amper_index = email_addr.find('@')
    username = email_addr[0:amper_index]
    domain = email_addr[amper_index + 1:len(email_addr)]
    if username == '' or domain == '' or email_addr.count('@') != 1:
        return -1
    else:
        return len(username)
