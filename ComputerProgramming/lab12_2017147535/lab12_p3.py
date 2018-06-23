import random
import copy

def Rand(lst1):  
    lst2 = []
    for k in range(len(lst1)):
        lst2.append('!')
        
    # random choice in lst1
    # lst3 is the past lst2 (deepcopy) if random choice in lst3 retry
    for k in range(len(lst1)):
        lst3 = copy.deepcopy(lst2)
        ran = False
        while not ran:
            lst2[k] = random.choice(lst1)
            if lst1[k] != lst2[k] and lst2[k] not in lst3:
                ran = True
    return lst2

def getFile():
    # Re-use code in lab11_p3.py
    input_file_opened = False
    while not input_file_opened:
        try:
            file_name = input('Enter a filename: ')
            input_file = open(file_name, 'r')
            input_file_opened = True
        except IOError:
            print ('File not found - please reenter')
            
    # Define encryption or decryption
    if file_name[len(file_name) - 3:len(file_name)] == 'txt':
        return ('txt', file_name, input_file)
    elif file_name[len(file_name) - 3:len(file_name)] == 'enc':
        return ('enc', file_name, input_file)

(how, file_name, input_file) = getFile()

# lst1 in lower-case letters, upper-case letters, digits(0-9),
# spaces (’ ’), and new-line characters.
lst1 = [' ']
for k in range(48, 58):
    lst1.append(chr(k))
for k in range(65, 91):
    lst1.append(chr(k))
for k in range(97, 123):
    lst1.append(chr(k))    
    
if how == 'txt':
    # lst2 use for convert key!        
    lst2 = Rand(lst1)

    # write key
    write_1 = open(file_name[:len(file_name) - 4] + '.key', 'w')
    for k in range(len(lst2)):
        write_1.write(lst1[k] + ',' +lst2[k] + '\n')
    write_1.close()

    # encryption
    write_2 = open(file_name[:len(file_name) - 4] + '.enc', 'w')
    for line in input_file:
        write_2 = open(file_name[:len(file_name) - 4] + '.enc', 'a')
        line = list(line)
        # if find value -> stop(break)
        for a in range(len(line)):
            for b in range(len(lst1)):
                if line[a] == lst1[b]:
                    line[a] = lst2[b]
                    break
        line = ''.join(line)
        write_2.write(line)
        write_2.close()
        
elif how == 'enc':
    write_1 = open(file_name[:len(file_name) - 4] + '.key', 'r')

    # make key to lst(lst2)
    lst2 = []
    eof = False
    while not eof:
        w1_line = write_1.readline()
        if w1_line == '':
            eof = True
        else:
            lst2.append(w1_line.strip('\n').split(','))

    # decryption!
    write_2 = open(file_name[:len(file_name) - 4] + '.txt', 'w')
    for line in input_file:
        write_2 = open(file_name[:len(file_name) - 4] + '.txt', 'a')
        line = list(line)
        # lst2 is net list.
        for a in range(len(line)):
            for b in range(len(lst2)):
                if line[a] == lst2[b][1]:
                    line[a] = lst1[b][0]
                    break
        line = ''.join(line)
        write_2.write(line)
        write_2.close()
