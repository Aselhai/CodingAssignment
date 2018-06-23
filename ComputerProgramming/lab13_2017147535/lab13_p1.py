def fib(n):
  '''Computes the n-th Fibonacci number.'''
  
  # if no meaningful value(n == 1 or n ==2) -> return 1
  if n == 1 or n == 2:
    return 1
  # if meaningful -> return fibonachi number
  else:
    return fib(n-1) + fib(n-2)
