def resetValuesInPlace(L, threshold):
    for x in range(len(L)):
       if L[x] > threshold:
           L[x] = 0
