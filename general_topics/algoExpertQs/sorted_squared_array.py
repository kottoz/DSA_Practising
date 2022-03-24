def sortedSquaredArray(array):
    # Write your code here.
    new_array = array.copy()
    for item_index in range(len(new_array)):
        new_array[item_index] = array[item_index] *  array[item_index] 
    new_array.reverse()
    return new_array

a = [-3, -2, -1]
r = sortedSquaredArray(a)
print(r)