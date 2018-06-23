class Range:

  def __init__(self, start, end):
    self.__start = start
    self.__end = end
    # If index is not self.__start <= self.__end, raise IndexError
    if not self.__start <= self.__end:
      raise IndexError
      
  def __str__(self):
    return (str(self.__start) + '...' + str(self.__end))
      
  def __lt__(range1, range2):
    if range1.__end < range2.__start:
      return True
    else:
      return False
