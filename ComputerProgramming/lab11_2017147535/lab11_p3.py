def getFile():
    '''
        Returns the file name and associated file object for reading the
        file  as tuple of the form (file_name, input_file).
    '''
    input_file_opened = False
    while not input_file_opened:
        try:
            file_name = input('Enter input file name (with extension): ')
            input_file = open(file_name, 'r')
            input_file_opened = True
        except IOError:
            print ('Input file not found - please reenter')
    return (file_name, input_file)

# Duplicate -> delete function dup!
def dup(lst1):
    lst2 = []
    for k in range(len(lst1)):
        if lst1[k] not in lst2:
            lst2.append(lst1[k])
    return lst2

def search(input_file):
    word_delimiters = (' ', ',', ';', ':', '.','\n',
                       '"',"'", '(', ')')
    lst = []

    # Not english -> all space ' '
    for line in input_file:
        line = line.lower()
        for k in word_delimiters:
            line = line.replace(k, ' ')
        lst = lst + line.split(' ')
       
    # Find NULL, If finded -> k = 0 condier length of lst.
    k = 0
    while k < len(lst):
        if lst[k] == '':
            del lst[k]
            k = 0
        k = k + 1
    lst = dup(lst)
    lst.sort()
    return lst

def countWords(input_file, file_name, lst):
    ''' Returns the number of occurrences
        of search_word in the provided input_file object.'''
    word_delimiters = (' ', ',', ';', ':', '.','\n',
                       '"',"'", '(', ')')
    # lst2 for return value 
    lst2 = []
    
    for search_word in lst:
        num_occurrences = 0
        search_word_len = len(search_word)
        input_file = open(file_name, 'r')
        for line in input_file:
            line = line.lower() #convert to all lower case characters.
            end_of_line = False
            begin_of_line = True
            while not end_of_line:
                try:
                    found_search_word = False
                    index = line.index(search_word)
                    if index == 0:
                        if begin_of_line and line[search_word_len] in word_delimiters:
                            found_search_word = True
                    elif index > 0:
                        if line[index - 1] in word_delimiters and line[index + search_word_len] in word_delimiters:
                            found_search_word = True
                    if found_search_word:
                        num_occurrences = num_occurrences + 1
                    begin_of_line = False
                    line = line[index + search_word_len: len(line)]
                except ValueError:
                    end_of_line = True
        lst2.append([search_word, num_occurrences])
    return lst2

file_name, input_file = getFile()

lst = search(input_file)
input_file = open(file_name, 'r')
lst2 = countWords(input_file, file_name, lst)

file_name = file_name[0:len(file_name) - 4]

open(file_name + '.wc', 'w')
for k in range(len(lst2)):
    output = open(file_name + '.wc', 'a')
    output.write(lst2[k][0])
    output.write(': ')
    output.write(str(lst2[k][1]))
    output.write('\n')
    
