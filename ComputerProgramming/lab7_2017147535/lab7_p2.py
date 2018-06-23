def modCount(n, m):
    b = 0
    for a in range(1, n + 1):
        if a % m == 0:
            b = b + 1
        else:
            pass
    return b
