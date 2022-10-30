array = [1,4,5,8,2,9,3,7,6,0]
print(f'Current unstored array: {array}')
print('The working of selection sort: ')
for index in range(len(array)):
    selection = index
    for compare in range(index,len(array),1):
        if array[selection] > array[compare]:
            selection = compare
    #this is swapping
    temp = array[index]
    array[index] = array[selection]
    array[selection] = temp
    #this is steps per iteration
    print(array)
print('\nThe Result For Selected Array:')
print(array)