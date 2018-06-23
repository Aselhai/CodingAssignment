import math

def openFiles():
    smoking_datafile_opend = False
    cancer_datafile_opend = False
    num_attempts = 4

    while ((not smoking_datafile_opend) or \
           (not cancer_datafile_opend)) \
           and (num_attempts > 0):
        try:
            if not smoking_datafile_opend:
                file_name = input('Enter air pollution data file name: ')
                smoking_datafile = open(file_name, 'r')
                smoking_datafile_opend = True

            if not cancer_datafile_opend:
                file_name = input('Enter lung cancer data file name: ')
                cancer_datafile = open(file_name, 'r')
                cancer_datafile_opend = True

        except IOError:
            print('File not found:', file_name + '.', 'Please reenter\n')
            num_attempts = num_attempts - 1

    if not smoking_datafile_opend or not cancer_datafile_opend:
        raise IOError('Too many attempts of reading input files')

    else:
        return (smoking_datafile, cancer_datafile)
    
def readFiles(smoking_datafile, cancer_datafile):
    smoking_data = []
    cancer_data = []
    empty_str = ''

    smoking_datafile.readline()
    cancer_datafile.readline()

    eof = False

    while not eof:
        s_line = smoking_datafile.readline()
        c_line = cancer_datafile.readline()
        if s_line == empty_str and c_line == empty_str:
            eof = True

        elif s_line != empty_str or c_line != empty_str:
            smoking_data.append(s_line.strip().split(','))
            cancer_data.append(c_line.strip().split(','))
    return (smoking_data, cancer_data)

def calculateCorrelation (smoking_data, cancer_data):
    # sort arrange!
    smoking_data.sort()
    cancer_data.sort()
        
    # inner list value make lower english.
    for k in range(len(smoking_data)):
        smoking_data[k][0] = smoking_data[k][0].lower()
    for k in range(len(cancer_data)):
        cancer_data[k][0] = cancer_data[k][0].lower()
    
    # lst1, lst2 use for state name
    lst1 = []
    lst2 = []

    for k in range(len(smoking_data)):
        lst1.append(smoking_data[k][0])
    for k in range(len(cancer_data)):
        lst2.append(cancer_data[k][0])
        
    k = 0  
    while k < len(smoking_data):
        if smoking_data[k][0] not in lst2:
            del smoking_data[k]
            k = 0
        k = k  + 1
        
    k = 0  
    while k < len(cancer_data):
        if cancer_data[k][0] not in lst1:
            del cancer_data[k]
            k = 0
        k = k  + 1    

    sum_smoking_vals = sum_cancer_vals = 0
    sum_smoking_sqrd = sum_cancer_sqrd = 0
    sum_products = 0
    num_values = len(smoking_data)

    for k in range(num_values):
        sum_smoking_vals = sum_smoking_vals + float(smoking_data[k][1])
        sum_cancer_vals = sum_cancer_vals + float(cancer_data[k][1])

        sum_smoking_sqrd = sum_smoking_sqrd + \
                            float(smoking_data[k][1]) ** 2
        sum_cancer_sqrd = sum_cancer_sqrd + \
                            float(cancer_data[k][1]) ** 2

        sum_products = sum_products + float(smoking_data[k][1]) * \
                       float(cancer_data[k][1])

    numer = (num_values * sum_products) - \
            (sum_smoking_vals * sum_cancer_vals)
    
    denom = math.sqrt(abs( \
        ((num_values * sum_smoking_sqrd) - (sum_smoking_vals ** 2)) * \
        ((num_values * sum_cancer_sqrd) - (sum_cancer_vals ** 2)) \
        ))
    return numer / denom

print('This program will determine the correlation (-1 to 1) between')
print('data on air pollution and incidences of lung cancer\n')

try:
    smoking_datafile, cancer_datafile = openFiles()
    smoking_data, cancer_data = readFiles(smoking_datafile, cancer_datafile)
    correlation = calculateCorrelation(smoking_data, cancer_data)
    print('r_value = ', correlation)
except IOError as e:
    print(str(e))
    print('Program terminated ...')
