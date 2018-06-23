import os
import copy

def countWords(file_name, search_word):
    ''' Returns the number of occurrences
        of search_word in the provided file_name object.'''
    input_file = open(file_name, 'r')
    num_occurrences = 0
    word_delimiters = (' ', ',', ';', ':', '.','\n',
                       '"',"'", '(', ')', '!')
    search_word_len = len(search_word)
    for line in input_file:
      end_of_line = False
      begin_of_line = True # the begin of line counts as a word_delimiter
      while not end_of_line:
        # print('>' + line.strip() + '<')
        try:   
          found_search_word = False
          index = line.index(search_word)
          if index == 0:
            # Only valid case for 'index == 0' is at begin of line.
            # In the middle of a line, line[index-1] must be a delimiter. If not,
            # the word lacks a LEFT delimiter and we're in the middle of a
            # word, for example at the second 'foo' in 'foofoo' when counting
            # 'foo'. Thus, index==0 is not possible in the middle of a line.
            if begin_of_line and line[search_word_len] in word_delimiters:
              found_search_word = True
          elif index > 0:
            # All matching cases in middle of line must have 'index > 0',
            # because line[index - 1] must be a delimiter! (So index=0 is
            # invalid, because the LEFT delimiter is missing.)
            if line[index - 1] in word_delimiters and \
                line[index + search_word_len] in word_delimiters:
              found_search_word = True
          if found_search_word:
            # print('Pos:', index)
            num_occurrences = num_occurrences + 1
          begin_of_line = False # we moved past the begin of line
          line = line[index + search_word_len: len(line)]
        except ValueError:
          end_of_line = True               
    if num_occurrences == 0:
        return False
    else:
        return True
  
def searchDir(directory, s):
    '''Recursively searches 'directory' for .txt files
    that contain string s.
    '''

    # In directory's file and folder list -> walk
    rtn1 = []
    rtn2 = []
    for (a, b, c) in os.walk(directory):
        for d in c:
            if countWords(a + '/' + d, s) == True and d[len(d)-3:] == 'txt':
                rtn1.append(a + '/' + d)
    for k in range(len(rtn1)):
        empty = ''
        st = rtn1[k]
        for l in range(len(st)):
            if st[l:1+2] == '\\':
                empty = empty + '/'
            if st[l] == chr(92):
                empty = empty + '/'
            else:
                empty = empty + st[l]
        rtn2.append(empty)
    return rtn2
