class AvgList(list):

  def computeAvg(list):
    try:
      a = 0
      for k in range(len(list)):
        float(list[k])
        a = a + list[k]
      return a / len(list)
    except:
      raise ValueError
