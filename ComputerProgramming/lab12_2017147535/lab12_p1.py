def addDailyTemp(mydict, day, temperature):
  if day not in mydict:
    mydict[day] = temperature
  return mydict
  
