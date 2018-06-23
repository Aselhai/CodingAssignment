from operator import itemgetter

list1 = []
list2 = []
J = False

fruit = input('Enter a fruit type (q to quit): ')
if fruit == 'q':
    exit =''
else:
    kg = int(input('Enter the weight in kg: '))
    list1.append(fruit)
    list1.append(kg)
    list2.append(list1)
    list1 = []

while fruit != 'q':
    fruit = input('Enter a fruit type (q to quit): ')
    if fruit == 'q':
        exit = ''
    else:
        kg = int(input('Enter the weight in kg: '))
        n = 0
        while n < len(list2):
            if str(fruit) in list2[n][0]:
                J = True
                break
            else:
                J = False
                n = n + 1
        if J == False:
            list1.append(fruit)
            list1.append(kg)
            list2.append(list1)
            list1 = []
        else:
            list2[n][1] = int(list2[n][1]) + int(kg)
        
list2.sort(key=itemgetter(0))
n = 0
    
for n in range(len(list2)):
    print(str(list2[n][0]) + ', ' + str(list2[n][1]) + 'kg.')

