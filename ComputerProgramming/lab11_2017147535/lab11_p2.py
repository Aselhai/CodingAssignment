def copyFiles(f1, f2, f3):
    # if Error! -> return -1
    try:
        # Read f1, f2 -> input1, input2 and write f3 -> output
        input1 = open(f1, 'r')
        input2 = open(f2, 'r')
        output = open(f3, 'w')
        line = input1.readline()
        # Use loop while '' apear!
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
    
    except:
        return -1
