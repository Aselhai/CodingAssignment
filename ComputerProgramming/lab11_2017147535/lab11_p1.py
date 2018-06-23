import time
import copy

work = []

def printSep():
  for ctr in range(0, size + 2):
    print('-', end='')
  print('')

def printWorld(world):
  for k in range(len(work)):
    print('|', end = '')
    for l in range(len(work[k])):
      print(work[k][l], end = '')
    print('|', end = '')
    print(' row', k)

def live_count(work2, k, l, live):
  try:
    if k < 0 or k > 20:
      raise Error
    if work2[k][l] == 'x':
      return live + 1
    elif work2[k][l] == ' ':
      return live
  except:
      return live
  

def rule(work):
  work2 = copy.deepcopy(work)
  
  for k in range(len(work2)):
    for l in range(len(work2[k])):
        live = 0
        live = live_count(work2, k-1, l-1, live)
        live = live_count(work2, k-1,   l, live)
        live = live_count(work2, k-1, l+1, live)
        live = live_count(work2,   k, l-1, live)
        live = live_count(work2,   k, l+1, live)
        live = live_count(work2, k+1, l-1, live)
        live = live_count(work2, k+1,   l, live)
        live = live_count(work2, k+1, l+1, live)

        if work2[k][l] == 'x':
          if live == 2 or live == 3:
            work[k][l] = 'x'
          else:
            work[k][l] = ' '
            
        elif work2[k][l] == ' ':
          if live == 3:
            work[k][l] = 'x'
          else:
            work[k][l] = ' '
##        print(k ,l ,live)
  return work

# Initialize work and tmp:
def Zero(work, size):
  # work list in list!
  for k in range(size):
    work.append([])

  # Initialize cellular use loop!
  for k in range(0, 3):
    while len(work[k]) != 1:
      work[k].append(' ')
    for l in range(1):
      work[k].append('x')
    while len(work[k]) != size:
      work[k].append(' ')
  
  for k in range(3, 10):
    while len(work[k]) != size:
      work[k].append(' ')

  for k in [10, 12]:
    while len(work[k]) != 10:
      work[k].append(' ')
    for l in range(3):
      work[k].append('x')
    while len(work[k]) != size:
      work[k].append(' ')

  for k in [11]:
    while len(work[k]) != 10:
      work[k].append(' ')
    for l in range(1):
      work[k].append('x')
    while len(work[k]) != size:
      work[k].append(' ')
      
  for k in range(13, size):
    while len(work[k]) != size:
      work[k].append(' ')
  
  return work

# Compute:
size = input('Grid sidelength (default 20): ')

check_size = False
while not check_size:
  try:
    size = int(size)
    check_size = True
  except:
    size = 20

if size < 20:
  size = 20

generation = input('Max generation: ')

check_gen = False
while not check_gen:
  try:
    generation = int(generation)
    if generation < 0:
      raise Error
    check_gen = True
  except:
    generation = input('Max generation: ')

  
a = 0
while a <= generation:
  if a == 0:
    work = Zero(work, size)
    printSep()
    printWorld(work)
    printSep()
    a = a + 1
    time.sleep(1)
  else:
    work = rule(work)
    printSep()
    printWorld(work)
    printSep()
    a = a + 1
    time.sleep(1)

  
