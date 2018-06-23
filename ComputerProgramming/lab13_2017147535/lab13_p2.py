def fibcalls(n):
  '''Computes the number of function calls required
  to compute the n-th Fibonacci number.
  '''
  
  if n == 1 or n == 2:
    return 1
  else:
    a = 0
    k = 1
    while k < n:
      a = a + fib(k)
      k = k + 1
    return a + 1

def fib(n):
  # if no meaningful value(n == 1 or n ==2) -> return 1
  if n == 1 or n == 2:
    return 1
  # if meaningful -> return fibonachi number
  else:
    return fib(n-1) + fib(n-2)
