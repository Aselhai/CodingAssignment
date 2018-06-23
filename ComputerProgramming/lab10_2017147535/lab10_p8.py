def copyFiles(f1, f2, f3):
    input1 = open(f1, 'r')
    input2 = open(f2, 'r')
    output = open(f3, 'w')
    
    line = input1.readline()
    while line != '':
        output.write(line)
        line = input1.readline()

    line = input2.readline()
    while line != '':
        output.write(line)
        line = input2.readline()

    input1.close()
    input2.close()
    output.close()

    return 0
