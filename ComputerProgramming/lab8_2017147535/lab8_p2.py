def resetValues(L, threshold):
    for x in range(len(L)):
       if L[x] > threshold:
           L[x] = 0
    return L
